#include "cmdengine.h"

/* KEYBOARD */

int Keyboard::getKeyPressed()
{
  return GetKeyPressed();
}

bool Keyboard::isKeyPressed(int key)
{
  return IsKeyPressed(key);
}

bool Keyboard::isKeyReleased(int key)
{
  return IsKeyReleased(key);
}

bool Keyboard::isKeyDown(int key)
{
  return IsKeyDown(key);
}


/* GAME WINDOW */

void GameWindow::startGuiMode(Color bgColor)
{
  BeginDrawing();
  clearColor(bgColor);
}

void GameWindow::startFrame()
{
  BeginMode2D(camera);
}

void GameWindow::clearColor(Color color)
{
  ClearBackground(color);
}

void GameWindow::endFrame()
{
  EndMode2D();
}

void GameWindow::endGuiMode()
{
  EndDrawing();
}

bool GameWindow::isOpen()
{
  return !WindowShouldClose();
}

void GameWindow::close()
{
  if (!textures.empty()){
    for (Texture2D* texture : textures) UnloadTexture(*texture);
  }
  CloseAudioDevice();
  CloseWindow();
}

bool CERectangle::intersectsWith(CERectangle target){
  return CheckCollisionRecs(rect, target.rect);
}

void CERectangle::draw(){
  // Make sure properties are up-to-date
  rect.x = x;
  rect.y = y;
  rect.width = w;
  rect.height = h;

  DrawRectangleRec(rect, color);
}

bool CECircle::intersectsWith(CECircle target){
  return CheckCollisionCircles((Vector2) { (float) x, (float) y }, radius, (Vector2) { (float) target.x, (float) target.y }, target.radius);
}

void CECircle::draw()
{
  DrawCircle(x, y, radius, color);
}

void TextBox::draw()
{
  DrawText(content.c_str(), x, y, textSize, color);
}

bool Mouse::isButtonDown(int button)
{
  return IsMouseButtonDown(button);
}

bool Mouse::isButtonPressed(int button)
{
  return IsMouseButtonPressed(button);
}

bool Mouse::isButtonReleased(int button)
{
  return IsMouseButtonReleased(button);
}

bool Mouse::isPressingObject(CERectangle obj)
{
  return isHoveringOver(obj) && IsMouseButtonDown(Left);
}

bool Mouse::isHoveringOver(CERectangle obj)
{
  // Hitbox for cursor
  CERectangle cursorHitbox(getX(), getY(), 10, 10, WHITE);
  return cursorHitbox.intersectsWith(obj);
}

int Mouse::getX()
{
  return GetMouseX();
}

int Mouse::getY()
{
  return GetMouseY();
}
