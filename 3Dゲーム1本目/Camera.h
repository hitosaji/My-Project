#pragma once
#include "DxLib.h"

class Camera
{
protected:
    float cameraX = 600.0f;
    float cameraY = 1500.0f;
    float cameraZ = -800.0f;

    bool isMoving = false;



private:
    //カメラの移動
    void CameraMovement();

    //カメラの向き
    void CameraOrientation();

    //カメラの歩く際の振動
    void CameraVibration();

    //カメラの視線の移動量
    void CameraSensitivity();

    // カメラ設定
    SetCameraPositionAndTarget_UpVecY(VGet(cameraX, cameraY + bobOffset, cameraZ), VGet(targetX, targetY + bobOffset, targetZ));

    
};