#pragma once
#include "raylib.h"
#include <string>
#include <vector>

class GameWindow {
  public:
  int width, height;
  int fps;
  Camera2D camera;
  std::vector<Texture2D> textures;
  std::string windowTitle;

  GameWindow(int w, int h, int fps, std::string title): width(w), height(h), windowTitle(title), fps(fps){
    InitWindow(width, height, windowTitle.c_str());
    SetTargetFPS(this->fps);

    camera = { 0 };
    camera.offset = { 0, 0 };
    camera.rotation = 0;
    camera.target = { 0, 0 };
    camera.zoom = 1.0f;
  }

  /// @brief Starts the GUI Mode, This mode must be started even if GUI isn't needed, This Mode doesn't use the camera meaning whatever is drawn in this doesn't move in the game world and its a part of the UI. Make sure to draw the UI when you're about to call endGuiMode as that makes the UI appear above everything
  /// @param bgColor 
  void startGuiMode(Color bgColor);
  void startFrame();
  void clearColor(Color color);
  void endFrame();
  /// @brief Ends the GUI Mode, draw the ui here to make it appear above everything else
  void endGuiMode();

  bool isOpen();

  void close();
};

class Keyboard {
  public:
  static int getKeyPressed();

  /// @brief Key Pressed
  /// @param key Raylib-style key (e.g, KEY_A, KEY_SPACE)
  /// @return bool
  static bool isKeyPressed(int key);

  /// @brief Key released
  /// @param key Raylib-style key (e.g, KEY_A, KEY_SPACE)
  /// @return bool
  static bool isKeyReleased(int key);

  /// @brief Key Held, Should be used for key combos
  /// @param key Raylib-style key (e.g, KEY_A, KEY_SPACE)
  /// @return bool
  static bool isKeyDown(int key);
};


/* Graphics */
class CERectangle {
  public:
  int x, y, w, h;
  Color color;

  Rectangle rect;

  CERectangle(int x, int y, int w, int h, Color color = RED): x(x), y(y), w(w), h(h), color(color){
    rect.x = x;
    rect.y = y;
    rect.width = w;
    rect.height = h;
  }

  bool intersectsWith(CERectangle target);
  void draw();
};

class CECircle {
  public:
  int x, y, radius;
  Color color;

  CECircle(int x, int y, int radius, Color color = RED): x(x), y(y), radius(radius), color(color){}

  bool intersectsWith(CECircle target);
  void draw();
};


/* TEXT */

class TextBox {
  public:
  std::string content;
  int textSize;
  Color color;
  int x, y;

  TextBox(int x, int y, std::string content, int textSize = 16, Color color = BLACK):
    x(x), y(y), content(content), textSize(textSize), color(color){}
  
  void draw();
};