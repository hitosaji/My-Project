#include "DxLib.h"
#include"Camera.h"
#include"Colider.h"
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

    Camera camera;

    // 壁の範囲
    VECTOR wallMin = VGet(7000.0f, 1000.0f, 1000.0f);
    VECTOR wallMax = VGet(1500.0f, 1000.0f, 1500.0f);

    int stageModel = MV1LoadModel("Stage3.mv1");

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
        
        camera.Update();

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
