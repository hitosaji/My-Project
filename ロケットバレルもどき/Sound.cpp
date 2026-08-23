#include "Sound.h"
#include "DxLib.h"

Sound::Sound()
{
}

void Sound::Init()
{
    soundhandle1 = LoadGraph("Sound/Explosion.mp3");

}