#include <stdio.h>
#include <random>
#include <time.h>

#include <ESAT/window.h>
#include <ESAT/draw.h>
#include <ESAT/sprite.h>
#include <ESAT/input.h>



#include "SDL/SDL_timer.h"

#include "../include/game_manager.h"
#include "../include/paddle.h"

int ESAT::main(int argc, char **argv) {

  //random seed
  srand(time(0));

  ESAT::WindowInit(GameManager::Instance()->kScreenWidth, GameManager::Instance()->kScreenHeight);

  Paddle main_paddle;
  main_paddle.init("paddle.png");

  main_paddle.pos_y_ = GameManager::Instance()->kScreenHeight - ESAT::SpriteHeight(main_paddle.sprite_);
  main_paddle.pos_x_ = (GameManager::Instance()->kScreenWidth / 2) - ESAT::SpriteHeight(main_paddle.sprite_);

  ///miliseconds pased from the last time that the game loop calls his functions
  long long int miliseconds = 0;
  
  while (ESAT::WindowIsOpened()){

    if (SDL_GetTicks() - miliseconds >= 16) {

      miliseconds = SDL_GetTicks();
      ESAT::DrawClear(0, 0, 0);

      main_paddle.input();
      main_paddle.update();
      main_paddle.draw();

      // End of current frame
      ESAT::WindowFrame();
    }

  }

  ESAT::WindowDestroy();
  return 0;
}