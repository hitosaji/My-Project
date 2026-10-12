#include "DxLib.h"
#include"Camera.h"
#include"Colider.h"
#include <math.h>
#include <tchar.h>

Colider colider;

VECTOR Camera::CameraMove()
{
    VECTOR nextPosition = cameraPosition;

    nextPosition.x -= cos(cameraYaw) * 15.0f;
    nextPosition.z += sin(cameraYaw) * 15.0f;

    return nextPosition;
}

void Camera::CameraMovement()
{

    if (CheckHitKey(KEY_INPUT_A))
    {
        VECTOR nextPosition = CameraMove();

        // 次の位置が壁の中ではなければ移動
        colider.WallColider(nextPosition.x, nextPosition.z);
        isMoving = true;
    }

    if (CheckHitKey(KEY_INPUT_D))
    {
        float nextX = cameraPosition.x + cos(cameraYaw) * 15.0f;
        float nextZ = cameraPosition.z - sin(cameraYaw) * 15.0f;

        // 次の位置が壁の中ではなければ移動
        colider.WallColider(cameraPosition.x, cameraPosition.z, nextX, nextZ);
        isMoving = true;
    }

    if (CheckHitKey(KEY_INPUT_W))
    {
        float nextX = cameraPosition.x + sin(cameraYaw) * 15.0f;
        float nextZ = cameraPosition.z + cos(cameraYaw) * 15.0f;

        // 次の位置が壁の中ではなければ移動
        // 次の位置が壁の中ではなければ移動
        colider.WallColider(cameraPosition.x, cameraPosition.z, nextX, nextZ);
        isMoving = true;
    }

    if (CheckHitKey(KEY_INPUT_S))
    {
        float nextX = cameraPosition.x - sin(cameraYaw) * 15.0f;
        float nextZ = cameraPosition.z - cos(cameraYaw) * 15.0f;

        // 次の位置が壁の中ではなければ移動
        colider.WallColider(cameraPosition.x, cameraPosition.z, nextX, nextZ);
        isMoving = true;
    }

    //SetCameraPositionAndTarget_UpVecY(VGet(cameraX, cameraY + bobOffset, cameraZ), VGet(targetX, targetY + bobOffset, targetZ));

}

//カメラの向き
void Camera::CameraOrientation()
{
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
};

//カメラの歩く際の振動
void Camera::CameraVibration()
{
    float cameraBobTime = 0.0f;

 if (isMoving)
 {
    cameraBobTime += 0.1f;
 }
  //歩く時の振動
  float bobOffset = sin(cameraBobTime) * 10.0f;
};

//カメラの視線の移動量
void Camera::CameraSensitivity()
{
    VECTOR targetPosition = VGet(
        cameraPosition.x + cos(cameraPitch) * sin(cameraYaw) * 1000.0f,
        cameraPosition.y + sin(cameraPitch) * 1000.0f,
        cameraPosition.z + cos(cameraPitch) * cos(cameraYaw) * 1000.0f
        );


};
