#include"Colider.h"
#include"Camera.h"

bool Colider::WallColider(float nextX, float nextZ)
{
    // ŽŸ‚ÌˆÊ’u‚ª•Ç‚Ì’†‚Å‚Í‚È‚¯‚ê‚ÎˆÚ“®
    if (!(nextX <= wallMinX && nextX >= wallMaxX &&
        nextZ >= wallMinZ && nextZ <= wallMaxZ))
    {
        return false;
    }

    return true;

};