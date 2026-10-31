#pragma once
#include"Colider.h"
#include"Camera.h"
class InitialWallCollider :Camera
{
public:

    struct Wall
    {
        float minX;
        float maxX;

        float minY;
        float maxY;

        float minZ;
        float maxZ;

        VECTOR min;
        VECTOR max;

    };

    Wall walls[4];

	InitialWallCollider();

	bool WallColider(float nextX, float nextZ, float wallMinX, float wallMaxX, float wallMinZ, float wallMaxZ);
};