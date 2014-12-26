#include <ESAT/window.h>
#include <ESAT/draw.h>
#include <ESAT/sprite.h>
#include <ESAT/input.h>


#include <stdio.h>


int ESAT::main(int argc, char **argv) {

  ESAT::WindowInit(640, 480);
  
  while (ESAT::WindowIsOpened()){
    ESAT::DrawClear(0, 0, 0);


    ESAT::WindowFrame();
  }

  ESAT::WindowDestroy();
  return 0;
}