#pragma once
#include "DxLib.h"
#include"Config.h"
#include"Colider.h"
#include<Vector>

class Camera:protected Colider
{
private:
    VECTOR cameraPosition = 
        VGet(Config::INITIAL_CAMERA_POSITION_X,
             Config::INITIAL_CAMERA_POSITION_Y, 
             Config::INITIAL_CAMERA_POSITION_Z);


    float cameraYaw = 0.0f;   // 左右の向き
    float cameraPitch = 0.0f; // 上下の向き
    float cameraBobTime = 0.0f;

    bool isMoving = false;


private:
    VECTOR CameraMove();
    //カメラの移動
    void CameraMovement();

    //カメラの向き
    void CameraOrientation();

    //カメラの歩く際の振動
    float CameraVibration();

    //カメラの視線の移動量
    VECTOR CameraSensitivity();

    //上記2つのカメラ関数をまとめる
    void CameraSetting();
};