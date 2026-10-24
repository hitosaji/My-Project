#pragma once
#include"Config.h"
class Colider
{
protected:
    // 壁の範囲
    float wallMinX = Config::WALL_EXTENT_X_1;
    float wallMaxX = Config::WALL_EXTENT_X_2;

    float wallMinY = Config::WALL_EXTENT_Y_1;
    float wallMaxY = Config::WALL_EXTENT_Y_2;

    float wallMinZ = Config::WALL_EXTENT_Z_1;
    float wallMaxZ = Config::WALL_EXTENT_Z_2;

    //四方の壁の当たり判定
    bool WallColider(float nextX,float nextZ);

    ////壁にぶつかった際の垂直な方向ベクトルを求める
    //VECTOR PushbackAngle();

    ////押し戻し処理
    //void PushBack();

};