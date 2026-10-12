#pragma once
#include"Camera.h"
class Colider:Camera
{
private:
    // •Ç‚Ì”ÍˆÍ
    float wallMinX = 7000.0f;
    float wallMaxX = 1500.0f;

    float wallMinY = 1000.0f;
    float wallMaxY = 1000.0f;

    float wallMinZ = 1000.0f;
    float wallMaxZ = 1500.0f;

    //Žl•û‚Ì•Ç‚Ì“–‚½‚è”»’è
    int WallColider(nextX,nextY);

    

};