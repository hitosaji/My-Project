#pragma once
namespace Config
{
    //カメラの初期座標
    const int INITIAL_CAMERA_POSITION_X = 600.0f;
    const int INITIAL_CAMERA_POSITION_Y = 1500.0f;
    const int INITIAL_CAMERA_POSITION_Z = -800.0f;

    //四方の壁の当たり判定・正面

    //四方の壁の当たり判定・左

    //四方の壁の当たり判定・右

    //四方の壁の当たり判定・背面

    //仮の当たり判定・上
    const float WALL_EXTENT_X_1 = 7000.0f;
    const float WALL_EXTENT_Y_1 = 1000.0f;
    const float WALL_EXTENT_Z_1 = 1000.0f;

    //仮の当たり判定・下
    const float WALL_EXTENT_X_2 = 1500.0f;
    const float WALL_EXTENT_Y_2 = 1000.0f;
    const float WALL_EXTENT_Z_2 = 1500.0f;

    //ステージモデルのそれぞれのサイズ
    const float STAGE_SIZE_X = 6.0f;
    const float STAGE_SIZE_X = 6.0f;
    const float STAGE_SIZE_X = 6.0f;

    //カメラの描画範囲
    const float CAMERA_RENDERING_NEAR = 132.0f;
    const float CAMERA_RENDERING_FAR = 50000.0f;

    //カメラの移動速度
    const float CAMERA_MOVE_SPEED = 15.0f;

    // カメラの回転速度
    const float CAMERA_ROTATION_SPEED = 0.02f;

    //カメラの上下角度の上限・上
    const float MAXIMUM_UP_CAMERA_ANGLE = 0.785f;

    const float MAXIMUM_DOWN_CAMERA_ANGLE = -0.785f;
    // 視線の先までの距離
    const float CAMERA_TARGET_DISTANCE = 1000.0f;
}