#pragma once
#include "CmdEngine"

class Sprite {
  public:
  GameWindow *parent;
  CERectangle *rect;
  std::string sprite;
  Texture2D texture;

  /// @brief Sprite constructor, The rect.color is the tint (WHITE for no tint)

  Sprite(std::string sprite, GameWindow *parent, CERectangle *rect):
    sprite(sprite), parent(parent), rect(rect){
      texture = LoadTexture(sprite.c_str());

      parent->textures.push_back(&texture);
    }
  

  void draw();

  /// @brief Disposes the Sprite, Or in other words, Unloads the sprite to avoid memory leaks
  void dispose();
};


class Audio {
  public:
  Sound sound;
  std::string path;

  Audio(std::string path): path(path){
    sound = LoadSound(path.c_str());
  }

  void play();
  void dispose();
};

class GameMusic {
  public:
  Music music;
  std::string path;

  GameMusic(std::string path, bool loop = true): path(path){
    music = LoadMusicStream(path.c_str());
    music.looping = loop;
  }

  void play();
  void dispose();
  void update();
};
