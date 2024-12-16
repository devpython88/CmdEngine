#include "userlogic.h"

void userlogic_onFrame(GameWindow *window){
  window->startGuiMode(WHITE); // set background to white
  window->startFrame();

  /* DRAWING LOGIC HERE */

  window->endFrame();

  /* GUI DRAWING LOGIC HERE */

  window->endGuiMode();
}
void userlogic_main(GameWindow *window){}