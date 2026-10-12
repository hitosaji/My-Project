#include "DxLib.h"
#include"Camera.h"
#include""
#include <math.h>
#include <tchar.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow)
{
    ChangeWindowMode(TRUE);

    SetFullScreenScalingMode(DX_FSSCALINGMODE_BILINEAR);

    SetGraphMode(1280, 720, 32);

    if (DxLib_Init() == -1)
        return -1;
    
    // 3D描画設定
    SetDrawScreen(DX_SCREEN_BACK);

    VECTOR cameraPosition = VGet(Config::INITIAL_CAMERA_POSITION_X, Config::INITIAL_CAMERA_POSITION_Y, Config::INITIAL_CAMERA_POSITION_Z);

    // 壁の範囲
    VECTOR wallMin = VGet(7000.0f, 1000.0f, 1000.0f);
    VECTOR wallMax = VGet(1500.0f, 1000.0f, 1500.0f);

    VECTOR nextPosition = cameraPosition;

    float cameraBobTime = 0.0f;

    float cameraYaw = 0.0f;   // 左右の向き
    float cameraPitch = 0.0f; // 上下の向き

    int stageModel = MV1LoadModel(_T("Stage2.mv1"));

    MV1SetScale(stageModel, VGet(6.0f, 6.0f, 6.0f));

    int meshNum = MV1GetMeshNum(stageModel);

    for (int i = 0; i < meshNum; i++)
    {
        MV1SetMeshBackCulling(stageModel, i, FALSE);
        MV1SetMeshVisible(stageModel, i, TRUE);
    }

    // カメラの描画範囲
    SetCameraNearFar(132.0f, 50000.0f);

    while (ProcessMessage() == 0)
    {
        ClearDrawScreen();

        SetBackgroundColor(100, 150, 200);
        
        bool isMoving = false;

        // カメラの位置を移動
        if (CheckHitKey(KEY_INPUT_A))
        {
            nextPosition.x += sin(cameraYaw) * 15.0f;
            nextPosition.z += cos(cameraYaw) * 15.0f;

            // 次の位置が壁の中ではなければ移動
            if (!(cameraPosition.x <= wallMin.x && cameraPosition.x >= wallMax.x &&
                cameraPosition.z >= wallMin.z && cameraPosition.z <= wallMax.z))
            {
                cameraPosition.x = nextPosition.x;
                cameraPosition.z = nextPosition.z;
            }
            isMoving = true;
        }

        if (CheckHitKey(KEY_INPUT_D))
        {
            nextPosition.x += sin(cameraYaw) * 15.0f;
            nextPosition.z += cos(cameraYaw) * 15.0f;

            // 次の位置が壁の中ではなければ移動
            if (!(cameraPosition.x <= wallMin.x && cameraPosition.x >= wallMax.x &&
                cameraPosition.z >= wallMin.z && cameraPosition.z <= wallMax.z))
            {
                cameraPosition.x = nextPosition.x;
                cameraPosition.z = nextPosition.z;
            }
            isMoving = true;
        }

        
        if (CheckHitKey(KEY_INPUT_W))
        {
            nextPosition.x += sin(cameraYaw) * 15.0f;
            nextPosition.z += cos(cameraYaw) * 15.0f;

            // 次の位置が壁の中ではなければ移動
            if (!(cameraPosition.x <= wallMin.x && cameraPosition.x >= wallMax.x &&
                cameraPosition.z >= wallMin.z && cameraPosition.z <= wallMax.z))
            {
                cameraPosition.x = nextPosition.x;
                cameraPosition.z = nextPosition.z;
            }
            isMoving = true;
        }

        if (CheckHitKey(KEY_INPUT_S))
        {
            nextPosition.x += sin(cameraYaw) * 15.0f;
            nextPosition.z += cos(cameraYaw) * 15.0f;

            // 次の位置が壁の中ではなければ移動
            if (!(cameraPosition.x <= wallMin.x && cameraPosition.x >= wallMax.x &&
                cameraPosition.z >= wallMin.z && cameraPosition.z <= wallMax.z))
            {
                cameraPosition.x = nextPosition.x;
                cameraPosition.z = nextPosition.z;
            }
            isMoving = true;
        }

        // カメラの向き
        if (CheckHitKey(KEY_INPUT_LEFT))
        {
            cameraYaw -= 0.02f;
        }

        if (CheckHitKey(KEY_INPUT_RIGHT))
        {
            cameraYaw += 0.02f;
        }

        if (CheckHitKey(KEY_INPUT_UP))
        {
            cameraPitch += 0.02f;

            if (cameraPitch > 0.785f)
            {
                cameraPitch = 0.785f;
            }
        }

        if (CheckHitKey(KEY_INPUT_DOWN))
        {
            cameraPitch -= 0.02f;

            if (cameraPitch < -0.785f)
            {
                cameraPitch = -0.785f;
            }
        }

        

        

        // 視線の先を計算
        VECTOR targetPosition = VGet(
               cameraPosition.x + cos(cameraPitch) * sin(cameraYaw) * 1000.0f,
               cameraPosition.y + sin(cameraPitch) * 1000.0f,
               cameraPosition.z + cos(cameraPitch) * cos(cameraYaw) * 1000.0f
        );

        // カメラ設定
        SetCameraPositionAndTarget_UpVecY(VGet(cameraPosition.x, cameraPosition.y + bobOffset, cameraPosition.z), 
                                          VGet(targetPosition.x, targetPosition.y + bobOffset, targetPosition.z));

        int matNum = MV1GetMaterialNum(stageModel);
        for (int i = 0; i < matNum; i++) 
        {
            // ディフューズ色を灰色に強制設定
            MV1SetMaterialDifColor(stageModel, i, GetColorF(0.75f, 0.75f, 0.75f, 1.0f));
        }

        SetUseLighting(FALSE);

        MV1DrawModel(stageModel);
        DrawLine3D(
            wallMin,
            VGet(wallMax.x, wallMin.y, wallMin.z),
            GetColor(255, 0, 0)
        );

        DrawLine3D(
            VGet(wallMax.x, wallMin.y, wallMin.z),
            VGet(wallMax.x, wallMin.y, wallMax.z),
            GetColor(255, 0, 0)
        );

        DrawLine3D(
            VGet(wallMax.x, wallMin.y, wallMax.z),
            VGet(wallMin.x, wallMin.y, wallMax.z),
            GetColor(255, 0, 0)
        );

        DrawLine3D(
            VGet(wallMin.x, wallMin.y, wallMax.z),
            wallMin,
            GetColor(255, 0, 0)
        );
        

        ScreenFlip();
    }

    for (int i = 0; i < meshNum; i++)
    {
        MV1SetMeshBackCulling(stageModel, i, TRUE);
        MV1SetMeshVisible(stageModel, i, TRUE);
    }
    MV1DeleteModel(stageModel);

    DxLib_End();

    return 0;
}
