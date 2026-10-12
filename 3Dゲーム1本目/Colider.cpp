#include"Colider.h"
#include"Camera.h"

int Colider::WallColider(nextX, nextY)
{
    // ŽŸ‚ÌˆÊ’u‚ª•Ç‚Ì’†‚Å‚Í‚È‚¯‚ê‚ÎˆÚ“®
    if (!(cameraX <= wallMinX && cameraX >= wallMaxX &&
        cameraZ >= wallMinZ && cameraZ <= wallMaxZ))
    {
        cameraX = nextX;
        cameraZ = nextZ;
    }

};