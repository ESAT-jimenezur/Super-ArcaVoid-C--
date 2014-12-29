#include <ESAT/window.h>
#include <ESAT/draw.h>
#include <ESAT/sprite.h>
#include <ESAT/input.h>


#include <stdio.h>

#include "../include/game_manager.h"

#include "../include/paddle.h"

int ESAT::main(int argc, char **argv) {

  ESAT::WindowInit(GameManager::Instance()->kScreenWidth, GameManager::Instance()->kScreenHeight);

  Paddle main_paddle;
  main_paddle.init("paddle.png", 0);

  main_paddle.pos_y_ = GameManager::Instance()->kScreenHeight - ESAT::SpriteHeight(main_paddle.sprite_);
  main_paddle.pos_x_ = 100;

  
  while (ESAT::WindowIsOpened()){
    ESAT::DrawClear(0, 0, 0);


    main_paddle.update();
    main_paddle.draw();


    ESAT::WindowFrame();
  }

  ESAT::WindowDestroy();
  return 0;
}