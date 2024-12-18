#include "extras.h"

void Sprite::draw()
{
  DrawTexture(texture, rect->x, rect->y, rect->color);
}

void Sprite::dispose()
{
  UnloadTexture(texture);
}

void Audio::play()
{
  PlaySound(sound);
}

void Audio::dispose()
{
  UnloadSound(sound);
}

void GameMusic::play()
{
  PlayMusicStream(music);
}

void GameMusic::dispose()
{
  UnloadMusicStream(music);
}

void GameMusic::update()
{
  UpdateMusicStream(music);
}
