#include "CmdEngine/CmdEngine"
#include "CmdEngine/CEPhysics"
#include "CmdEngine/Extras"

int main(int argc, char const *argv[])
{
  GameWindow gameWindow(800, 600, 60, "My Game");

  while (gameWindow.isOpen()){

    gameWindow.startGuiMode(WHITE);
    gameWindow.startFrame();

    gameWindow.endFrame();
    
    gameWindow.endGuiMode();
  }

  gameWindow.close();
  return 0;
}
