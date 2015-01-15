/* Main class
 *
 * @author Jose Luis Jimenez Urbano | < ijos@ijos.es > | < @iJos >
 * 
 * TODO:
 *
 * PREGUNTAS PARA GUSTAVO:
 *  Como detectar colision en paddle (metodo optimo) -> Por pixel
 *  Los ladrillos deben ser sprites? o mejor pintados con la libreria de esat? -> ESAT
 *   --Matriz? -> Si
 *  Movimiento más fluido en le paddle... (metodo) -> Raton
 */

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
#include "../include/ball.h"
#include "../include/brick.h"
#include "../include/animation.h"
#include "../include/hud.h"

int ESAT::main(int argc, char **argv) {

  //random seed
  srand(time(0));

  ESAT::WindowInit(GameManager::Instance()->kScreenWidth, GameManager::Instance()->kScreenHeight);
  
  // Creating a Paddle
  Paddle main_paddle;
  main_paddle.init("paddle.png");

  main_paddle.pos_y_ = GameManager::Instance()->kScreenHeight - ESAT::SpriteHeight(main_paddle.sprite_);
  main_paddle.pos_x_ = (GameManager::Instance()->kScreenWidth / 2) - ESAT::SpriteHeight(main_paddle.sprite_);

  // Creating a Ball
  Ball main_ball;
  main_ball.init();

  //Hud
  Hud hud;

  //Bricks
  int brick_pos_x_ = 0;
  int brick_pos_y_ = 0;
  int tmp_vertical_offset_ = 0;
  int tmp_horizontal_offset_ = 0;

  Brick bricks[GameManager::kBricks_amount];
  for (int i = 0; i < GameManager::kBricks_amount; ++i){
    
    //Little and dirty fix to deal with first line offsets
    tmp_vertical_offset_ = (i == 0) ? 0 : GameManager::kBrick_height + GameManager::kBricks_vertical_offset;
    tmp_horizontal_offset_ = (i % GameManager::kBricks_per_line == 0) ? 0 : GameManager::kBrick_width + GameManager::kBricks_horizontal_offset;

    //Line Break
    if (i % GameManager::kBricks_per_line == 0){
      brick_pos_y_ = brick_pos_y_ + (tmp_vertical_offset_);
      brick_pos_x_ = 0;
    }

    bricks[i].init();
    bricks[i].position(brick_pos_x_ + (tmp_horizontal_offset_), brick_pos_y_);
    
    //bricks[i].setBrickColor(rand() % 255, rand() % 255, rand() % 255, 255);

    bricks[i].size(GameManager::kBrick_width, GameManager::kBrick_height);

    brick_pos_x_ = brick_pos_x_ + (tmp_horizontal_offset_);
  }


  ///miliseconds pased from the last time that the game loop calls his functions
  long long int miliseconds = 0;
  unsigned int frames_counter = 0;
  while (ESAT::WindowIsOpened()){

    if (SDL_GetTicks() - miliseconds >= 16) {

      miliseconds = SDL_GetTicks();
      ESAT::DrawClear(0, 0, 0);

      //Input
      main_paddle.input();

      //Update
      main_paddle.update();

      main_ball.update();
      main_ball.paddleCollision(main_paddle);
      main_ball.brickCollision(bricks);

      //Draw
      main_paddle.draw();
      main_ball.draw();

      for (int i = 0; i < GameManager::kBricks_amount; ++i){
        bricks[i].draw();
      }
     

      if (main_ball.collision_with_brick_ && frames_counter >= 0 && frames_counter < GameManager::kAnimation_duration){
        Animation animation;
        vector2 position;
        position.pos_x_ = GameManager::kAnimation_position_x;
        position.pos_y_ = GameManager::kAnimation_position_y - frames_counter;
        animation.animateText("+100", position);
        frames_counter++;
      }

      if (frames_counter >= GameManager::kAnimation_duration){
        frames_counter = 0;
        main_ball.collision_with_brick_ = false;
      }
      

      
      
      hud.draw();


      // End of current frame
      ESAT::WindowFrame();
    }

  }

  ESAT::WindowDestroy();
  return 0;
}