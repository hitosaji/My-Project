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
    float cameraY = 500.0f;
    float cameraZ = -800.0f;

    float cameraYaw = 0.0f;   // 左右の向き
    float cameraPitch = 0.0f; // 上下の向き

    int stageModel = MV1LoadModel(_T("Stage2.mv1"));

    int meshNum = MV1GetMeshNum(stageModel);

    for (int i = 0; i < meshNum; i++)
    {
        MV1SetMeshBackCulling(stageModel, i, FALSE);
        MV1SetMeshVisible(stageModel, i, TRUE);
    }

    // カメラの描画範囲
    SetCameraNearFar(132.0f, 33000.0f);

    while (ProcessMessage() == 0)
    {
        ClearDrawScreen();

        SetBackgroundColor(100, 150, 200);
        //// カメラを設定
        //SetCameraPositionAndTarget_UpVecY(
        //    VGet(750.0f, 0.0f, -200.0f),
        //    VGet(750.0f, 1200.0f, 10.0f)
        //);

         // カメラの位置を移動
        if (CheckHitKey(KEY_INPUT_A))
        {
            cameraX -= cos(cameraYaw) * 5.0f;
            cameraZ += sin(cameraYaw) * 5.0f;
        }

        if (CheckHitKey(KEY_INPUT_D))
        {
            cameraX += cos(cameraYaw) * 5.0f;
            cameraZ -= sin(cameraYaw) * 5.0f;
        }
        

        if (CheckHitKey(KEY_INPUT_W))
        {
            cameraX += sin(cameraYaw) * 5.0f;
            cameraZ += cos(cameraYaw) * 5.0f;
        }

        if (CheckHitKey(KEY_INPUT_S))
        {
            cameraX -= sin(cameraYaw) * 5.0f;
            cameraZ -= cos(cameraYaw) * 5.0f;
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
        }

        if (CheckHitKey(KEY_INPUT_DOWN))
        {
            cameraPitch -= 0.02f;
        }

        // 視線の先を計算
        float targetX =
            cameraX + cos(cameraPitch) * sin(cameraYaw) * 1000.0f;

        float targetY =
            cameraY + sin(cameraPitch) * 1000.0f;

        float targetZ =
            cameraZ + cos(cameraPitch) * cos(cameraYaw) * 1000.0f;

        // カメラ設定
        SetCameraPositionAndTarget_UpVecY(
            VGet(cameraX, cameraY, cameraZ),
            VGet(targetX, targetY, targetZ)
        );

        int matNum = MV1GetMaterialNum(stageModel);
        for (int i = 0; i < matNum; i++) {
            // ディフューズ色を灰色に強制設定
            MV1SetMaterialDifColor(stageModel, i, GetColorF(0.75f, 0.75f, 0.75f, 1.0f));
        }

        MV1DrawModel(stageModel);

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

