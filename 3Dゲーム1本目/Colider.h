#pragma once
#include"Config.h"
class Colider
{
protected:
    // •Ç‚Ì”ÍˆÍ
    float wallMinX = Config::WALL_EXTENT_X_1;
    float wallMaxX = Config::WALL_EXTENT_X_2;

    float wallMinY = Config::WALL_EXTENT_Y_1;
    float wallMaxY = Config::WALL_EXTENT_Y_2;

    float wallMinZ = Config::WALL_EXTENT_Z_1;
    float wallMaxZ = Config::WALL_EXTENT_Z_2;

    //Žl•û‚Ì•Ç‚Ì“–‚½‚è”»’è
    bool WallColider(float nextX,float nextZ);

    

};