#include "CmdEngine/CmdEngine"
#include "CmdEngine/CEPhysics"

int main(int argc, char const *argv[])
{
  GameWindow gameWindow(800, 600, 60, "My Game");
  CERectangle player(20, 10, 50, 50);
  CERectanglePhysicsBasic playerPhysics(0.1f, 0.1f, &player);

  TextBox textBox(0, 0, "Hello!");

  while (gameWindow.isOpen()){
    gameWindow.startGuiMode(WHITE);
    
    gameWindow.startFrame();

    playerPhysics.applyYPhysics();
    player.draw();

    gameWindow.camera.target.x += playerPhysics.velocityX;
    gameWindow.camera.target.y += playerPhysics.velocityY;

    gameWindow.endFrame();

    textBox.draw();

    gameWindow.endGuiMode();
  }

  gameWindow.close();
  return 0;
}
