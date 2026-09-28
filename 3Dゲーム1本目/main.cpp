#include "DxLib.h"
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

    float cameraX = 600.0f;
    float cameraY = 1500.0f;
    float cameraZ = -800.0f;

    // 壁の範囲
    float wallMinX = cameraX - 7000.0f;
    float wallMaxX = cameraX + 100.0f;

    float wallMinY = cameraY - 70.0f;
    float wallMaxY = cameraY + 100.0f;

    float wallMinZ = cameraZ - 100.0f;
    float wallMaxZ = cameraZ + 100.0f;

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
        //// カメラを設定
        //SetCameraPositionAndTarget_UpVecY(
        //    VGet(750.0f, 0.0f, -200.0f),
        //    VGet(750.0f, 1200.0f, 10.0f)
        //);
        bool isMoving = false;

        // カメラの位置を移動
        if (CheckHitKey(KEY_INPUT_A))
        {
            float nextX = cameraX + sin(cameraYaw) * 5.0f;
            float nextZ = cameraZ + cos(cameraYaw) * 5.0f;

            // 次の位置が壁の中ではなければ移動
            if (!(nextX >= wallMinX && nextX <= wallMaxX &&
                nextZ >= wallMinZ && nextZ <= wallMaxZ))
            {
                cameraX = nextX;
                cameraZ = nextZ;
            }
            isMoving = true;
        }

        if (CheckHitKey(KEY_INPUT_D))
        {
            float nextX = cameraX + sin(cameraYaw) * 5.0f;
            float nextZ = cameraZ + cos(cameraYaw) * 5.0f;

            // 次の位置が壁の中ではなければ移動
            if (!(nextX >= wallMinX && nextX <= wallMaxX &&
                nextZ >= wallMinZ && nextZ <= wallMaxZ))
            {
                cameraX = nextX;
                cameraZ = nextZ;
            }
            isMoving = true;
        }


        if (CheckHitKey(KEY_INPUT_W))
        {
            float nextX = cameraX + sin(cameraYaw) * 5.0f;
            float nextZ = cameraZ + cos(cameraYaw) * 5.0f;

            // 次の位置が壁の中ではなければ移動
            if (!(nextX >= wallMinX && nextX <= wallMaxX &&
                nextZ >= wallMinZ && nextZ <= wallMaxZ))
            {
                cameraX = nextX;
                cameraZ = nextZ;
            }
            isMoving = true;
        }

        if (CheckHitKey(KEY_INPUT_S))
        {
            float nextX = cameraX + sin(cameraYaw) * 5.0f;
            float nextZ = cameraZ + cos(cameraYaw) * 5.0f;

            // 次の位置が壁の中ではなければ移動
            if (!(nextX >= wallMinX && nextX <= wallMaxX &&
                nextZ >= wallMinZ && nextZ <= wallMaxZ))
            {
                cameraX = nextX;
                cameraZ = nextZ;
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
                cameraPitch = 0.785f;
        }

        if (CheckHitKey(KEY_INPUT_DOWN))
        {
            cameraPitch -= 0.02f;

            if (cameraPitch < -0.785f)
                cameraPitch = -0.785f;
        }

        if (isMoving)
        {
            cameraBobTime += 0.1f;
        }

        float bobOffset = sin(cameraBobTime) * 6.0f;

        // 視線の先を計算
        float targetX =
            cameraX + cos(cameraPitch) * sin(cameraYaw) * 1000.0f;

        float targetY =
            cameraY + sin(cameraPitch) * 1000.0f;

        float targetZ =
            cameraZ + cos(cameraPitch) * cos(cameraYaw) * 1000.0f;

        // カメラ設定
        SetCameraPositionAndTarget_UpVecY(VGet(cameraX, cameraY + bobOffset, cameraZ), VGet(targetX, targetY + bobOffset, targetZ));

        int matNum = MV1GetMaterialNum(stageModel);
        for (int i = 0; i < matNum; i++) {
            // ディフューズ色を灰色に強制設定
            MV1SetMaterialDifColor(stageModel, i, GetColorF(0.75f, 0.75f, 0.75f, 1.0f));
        }

        SetUseLighting(FALSE);

        MV1DrawModel(stageModel);
        DrawLine3D(
            VGet(wallMinX, wallMinY, wallMinZ),
            VGet(wallMaxX, wallMinY, wallMinZ),
            GetColor(255, 0, 0)
        );

        DrawLine3D(
            VGet(wallMaxX, wallMinY, wallMinZ),
            VGet(wallMaxX, wallMinY, wallMaxZ),
            GetColor(255, 0, 0)
        );

        DrawLine3D(
            VGet(wallMaxX, wallMinY, wallMaxZ),
            VGet(wallMinX, wallMinY, wallMaxZ),
            GetColor(255, 0, 0)
        );

        DrawLine3D(
            VGet(wallMinX, wallMinY, wallMaxZ),
            VGet(wallMinX, wallMinY, wallMinZ),
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
