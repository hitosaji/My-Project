#include "DxLib.h"



int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow)
{
    ChangeWindowMode(TRUE);

    SetFullScreenScalingMode(DX_FSSCALINGMODE_BILINEAR);

    SetGraphMode(1280, 720, 32);

    if (DxLib_Init() == -1)
        return -1;

    // 3Dï`âÊê›íË
    SetDrawScreen(DX_SCREEN_BACK);

    while (ProcessMessage() == 0)
    {
        ClearDrawScreen();

        // ÉJÉÅÉâÇê›íË
        SetCameraPositionAndTarget_UpVecY(
            VGet(750.0f, 0.0f, -200.0f),
            VGet(750.0f, 1200.0f, 10.0f)
        );

        DrawLine3D(
            VGet(500.0f, 400.0f, 0.0f),
            VGet(700.0f, 400.0f, 0.0f),
            GetColor(255, 255, 255));

        DrawLine3D(
            VGet(500.0f, 400.0f, 0.0f),
            VGet(662.5f, 275.0f, 0.0f),
            GetColor(255, 255, 255));

        DrawLine3D(
            VGet(600.0f, 475.0f, 0.0f),
            VGet(662.5f, 275.0f, 0.0f),
            GetColor(255, 255, 255));

        DrawLine3D(
            VGet(600.0f, 475.0f, 0.0f),
            VGet(537.5f, 275.0f, 0.0f),
            GetColor(255, 255, 255));

        DrawLine3D(
            VGet(537.5f, 275.0f, 0.0f),
            VGet(700.0f, 400.0f, 0.0f),
            GetColor(255, 255, 255));

        /*DrawLine3D(
            VGet(500.0f, 400.0f, 200.0f),
            VGet(700.0f, 400.0f, 0.0f),
            GetColor(255, 255, 255));

        DrawLine3D(
            VGet(500.0f, 400.0f, 0.0f),
            VGet(662.5f, 275.0f, 162.5f),
            GetColor(255, 255, 255));

        DrawLine3D(
            VGet(600.0f, 475.0f, 100.0f),
            VGet(662.5f, 275.0f, 0.0f),
            GetColor(255, 255, 255));

        DrawLine3D(
            VGet(600.0f, 475.0f, 100.0f),
            VGet(537.5f, 275.0f, 37.5f),
            GetColor(255, 255, 255));

        DrawLine3D(
            VGet(537.5f, 275.0f, 37.5f),
            VGet(700.0f, 400.0f, 200.0f),
            GetColor(255, 255, 255));*/


        ScreenFlip();
    }

    DxLib_End();

    return 0;
}