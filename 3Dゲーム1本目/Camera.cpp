#include "DxLib.h"
#include"Camera.h"
#include"Colider.h"
#include <math.h>
#include <tchar.h>

void Camera::CameraMovement()
{
    if (CheckHitKey(KEY_INPUT_A))
    {
        float nextX = cameraX - cos(cameraYaw) * 15.0f;
        float nextZ = cameraZ + sin(cameraYaw) * 15.0f;

        // 次の位置が壁の中ではなければ移動
        if (!(cameraX <= wallMinX && cameraX >= wallMaxX &&
            cameraZ >= wallMinZ && cameraZ <= wallMaxZ))
        {
            cameraX = nextX;
            cameraZ = nextZ;
        }
        isMoving = true;
    }

    if (CheckHitKey(KEY_INPUT_D))
    {
        float nextX = cameraX + cos(cameraYaw) * 15.0f;
        float nextZ = cameraZ - sin(cameraYaw) * 15.0f;

        // 次の位置が壁の中ではなければ移動
        if (!(cameraX <= wallMinX && cameraX >= wallMaxX &&
            cameraZ >= wallMinZ && cameraZ <= wallMaxZ))
        {
            cameraX = nextX;
            cameraZ = nextZ;
        }
        isMoving = true;
    }


    if (CheckHitKey(KEY_INPUT_W))
    {
        float nextX = cameraX + sin(cameraYaw) * 15.0f;
        float nextZ = cameraZ + cos(cameraYaw) * 15.0f;

        // 次の位置が壁の中ではなければ移動
        if (!(cameraX <= wallMinX && cameraX >= wallMaxX &&
            cameraZ >= wallMinZ && cameraZ <= wallMaxZ))
        {
            cameraX = nextX;
            cameraZ = nextZ;
        }
        isMoving = true;
    }

    if (CheckHitKey(KEY_INPUT_S))
    {
        float nextX = cameraX - sin(cameraYaw) * 15.0f;
        float nextZ = cameraZ - cos(cameraYaw) * 15.0f;

        // 次の位置が壁の中ではなければ移動
        if (!(cameraX <= wallMinX && cameraX >= wallMaxX &&
            cameraZ >= wallMinZ && cameraZ <= wallMaxZ))
        {
            cameraX = nextX;
            cameraZ = nextZ;
        }
        isMoving = true;
    }
}