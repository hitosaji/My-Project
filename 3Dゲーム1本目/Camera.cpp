#include "DxLib.h"
#include"Camera.h"
#include"Colider.h"
#include <math.h>
#include <tchar.h>

//カメラの移動
void Camera::CameraMovement()
{
    isMoving = false;

    float nextX, nextZ;
    
    if (CheckHitKey(KEY_INPUT_A))
    {
        nextX = cameraPosition.x - cos(cameraYaw) * Config::CAMERA_MOVE_SPEED;
        nextZ = cameraPosition.z + sin(cameraYaw) * Config::CAMERA_MOVE_SPEED;

        // 次の位置が壁の中ではなければ移動
        if (WallColider(nextX, nextZ))
        {
            cameraPosition.x = nextX;
            cameraPosition.z = nextZ;
        }

        isMoving = true;
    }

    if (CheckHitKey(KEY_INPUT_D))
    {
        nextX = cameraPosition.x + cos(cameraYaw) * Config::CAMERA_MOVE_SPEED;
        nextZ = cameraPosition.z - sin(cameraYaw) * Config::CAMERA_MOVE_SPEED;

        // 次の位置が壁の中ではなければ移動
        if (WallColider(nextX, nextZ))
        {
            cameraPosition.x = nextX;
            cameraPosition.z = nextZ;
        }

        isMoving = true;
    }

    if (CheckHitKey(KEY_INPUT_W))
    {
        nextX = cameraPosition.x + sin(cameraYaw) * Config::CAMERA_MOVE_SPEED;
        nextZ = cameraPosition.z + cos(cameraYaw) * Config::CAMERA_MOVE_SPEED;

        // 次の位置が壁の中ではなければ移動
        if (WallColider(nextX, nextZ))
        {
            cameraPosition.x = nextX;
            cameraPosition.z = nextZ;
        }

        isMoving = true;
    }

    if (CheckHitKey(KEY_INPUT_S))
    {
        nextX = cameraPosition.x - sin(cameraYaw) * Config::CAMERA_MOVE_SPEED;
        nextZ = cameraPosition.z - cos(cameraYaw) * Config::CAMERA_MOVE_SPEED;

        // 次の位置が壁の中ではなければ移動
        if (WallColider(nextX, nextZ))
        {
            cameraPosition.x = nextX;
            cameraPosition.z = nextZ;
        }

        isMoving = true;
    }
}


//カメラの向き
void Camera::CameraOrientation()
{
    if (CheckHitKey(KEY_INPUT_LEFT))
    {
        cameraYaw -= Config::CAMERA_ROTATION_SPEED;
    }

    if (CheckHitKey(KEY_INPUT_RIGHT))
    {
        cameraYaw += Config::CAMERA_ROTATION_SPEED;
    }

    if (CheckHitKey(KEY_INPUT_UP))
    {
        cameraPitch += Config::CAMERA_ROTATION_SPEED;

        if (cameraPitch > Config::MAXIMUM_UP_CAMERA_ANGLE)
        {
            cameraPitch = Config::MAXIMUM_UP_CAMERA_ANGLE;
        }
    }

    if (CheckHitKey(KEY_INPUT_DOWN))
    {
        cameraPitch -= Config::CAMERA_ROTATION_SPEED;

        if (cameraPitch < Config::MAXIMUM_DOWN_CAMERA_ANGLE)
        {
            cameraPitch = Config::MAXIMUM_DOWN_CAMERA_ANGLE;
        }
    }
};


//カメラの歩く際の振動
float Camera::CameraVibration()
{
 if (isMoving)
 {
    cameraBobTime += Config::CAMERA_VIBRATION_TIMER;
 }
  //歩く時の振動
 return sin(cameraBobTime) * Config::CAMERA_VIBRATION_TIME;
};

//カメラの視線の移動量
VECTOR Camera::CameraSensitivity()
{
    VECTOR targetPosition = VGet(
        cameraPosition.x + cos(cameraPitch) * sin(cameraYaw) * Config::CAMERA_TARGET_DISTANCE,
        cameraPosition.y + sin(cameraPitch) * Config::CAMERA_TARGET_DISTANCE,
        cameraPosition.z + cos(cameraPitch) * cos(cameraYaw) * Config::CAMERA_TARGET_DISTANCE
        );

    return targetPosition;
};


void Camera::CameraSetting()
{
    float bobOffset = CameraVibration();
    VECTOR targetPosition = CameraSensitivity();

    SetCameraPositionAndTarget_UpVecY(
        VGet(cameraPosition.x,
             cameraPosition.y + bobOffset,
             cameraPosition.z),
            
        VGet(targetPosition.x,
             targetPosition.y + bobOffset,
             targetPosition.z)
    );
}

float Camera::CameraCollisionPush()
{


};

//上記の関数をまとめて更新させる
void Camera::Update()
{
    CameraMovement();
    CameraOrientation();
    CameraSetting();
}