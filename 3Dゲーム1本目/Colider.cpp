#include"Colider.h"
#include"Camera.h"

bool Colider::WallColider(float nextX, float nextZ)
{
    // ŽŸ‚ÌˆÊ’u‚ª•Ç‚Ì’†‚Å‚Í‚È‚¯‚ê‚ÎˆÚ“®
    if (!(cameraX <= wallMinX && cameraX >= wallMaxX &&
        cameraZ >= wallMinZ && cameraZ <= wallMaxZ))
    {
        cameraX = nextX;
        cameraZ = nextZ;
    }

};