#include"InitialWallCollider.h"
#include"Colider.h"
#include"Camera.h"

InitialWallCollider::InitialWallCollider()
{
    Camera camera;
}

bool WallColider(float nextX, float nextZ, float wallMinX, float wallMaxX, float wallMinZ, float wallMaxZ)
{
    nextX = camera.cameraPos.x;

    // ŽŸ‚ÌˆÊ’u‚ª•Ç‚Ì’†‚Å‚Í‚È‚¯‚ê‚ÎˆÚ“®
    if (nextX <= wallMinX && nextX >= wallMaxX &&
        nextZ >= wallMinZ && nextZ <= wallMaxZ)
    {
        return false;
    }

    return true;

};