#include "CmdEngine/CmdEngine"
#include "userlogic.h"

int main(){
  GameWindow window(WIDTH, HEIGHT, FRAMERATE, TITLE);

  userlogic_main(&window); // initialize user logic

  while (window.isOpen()){
    userlogic_onFrame(&window);
  }

  window.close();
  return 0;
}