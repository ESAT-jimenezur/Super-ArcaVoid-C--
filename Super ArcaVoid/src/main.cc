﻿/* Main class
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


/* Extra - Examen
 * 25% prob on romper cae powerup (puntos) + efecto adicional temporal
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
#include "../include/main_menu.h"
#include "../include/paddle.h"
#include "../include/ball.h"
#include "../include/brick.h"
#include "../include/animation.h"
#include "../include/drop.h"
#include "../include/hud.h"

int ESAT::main(int argc, char **argv) {

  //random seed
  srand(time(0));

  ESAT::WindowInit(GameManager::Instance()->kScreenWidth, GameManager::Instance()->kScreenHeight);
  
  // Main Menu
  MainMenu main_menu;

  // Creating a Paddle
  Paddle main_paddle, secondary_paddle;
  main_paddle.init("paddle.png");
  secondary_paddle.init("paddle.png");
  secondary_paddle.is_secondary = true;

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
  unsigned int frames_counter_anim = 0;
  unsigned int frames_counter_drop = 0;
  unsigned int powerup_counter = 0;
  while (ESAT::WindowIsOpened() && !GameManager::should_exit){

    if (SDL_GetTicks() - miliseconds >= 16) {

      miliseconds = SDL_GetTicks();
      ESAT::DrawClear(0, 0, 0);

      switch (GameManager::selected_scene_){
        case (GameManager::scene_main_menu) : {
          main_menu.input();
          main_menu.showMenu();
        }
        break;
        case(GameManager::scene_game) : {
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
          if (main_ball.collision_with_brick_ && frames_counter_anim >= 0 && frames_counter_anim < GameManager::kAnimation_duration){
            Animation animation;
            vector2 position;
            position.pos_x_ = GameManager::kAnimation_position_x;
            position.pos_y_ = GameManager::kAnimation_position_y - frames_counter_anim;
            animation.animateText("+100", position);
            frames_counter_anim++;
          }
          if (frames_counter_anim >= GameManager::kAnimation_duration){
            frames_counter_anim = 0;
            main_ball.collision_with_brick_ = false;
          }


          // Object generation-related work
          if (GameManager::is_dropping && GameManager::drop_is_falling && frames_counter_drop <= GameManager::Instance()->kScreenHeight){
            Drop drop;
            drop.init();
            drop.createDrop(GameManager::kAnimation_position_x + 25, GameManager::kAnimation_position_y + frames_counter_drop);
            drop.fall();
            frames_counter_drop += 4;

            //printf("%f %f\n", drop.pos_x_, drop.pos_y_);

            if (drop.pos_x_ >= main_paddle.pos_x_ && drop.pos_x_ <= main_paddle.pos_x_ + ESAT::SpriteWidth(main_paddle.sprite_)
              && drop.pos_y_ >= main_paddle.pos_y_ && drop.pos_y_ <= main_paddle.pos_y_ + ESAT::SpriteHeight(main_paddle.sprite_)){
             
              GameManager::is_dropping = false;
              GameManager::drop_is_falling = false;
              GameManager::user_have_powerup = true;
            }

          }
          if (frames_counter_drop >= GameManager::Instance()->kScreenHeight || GameManager::user_have_powerup){
            frames_counter_drop = 0;
            GameManager::is_dropping = 0;
            GameManager::drop_is_falling = 0;
            GameManager::double_paddle = true;
          }

          // PowerUp effects
          // Second paddle
          if (GameManager::user_have_powerup && powerup_counter <= 1000){

            secondary_paddle.pos_y_ = main_paddle.pos_y_;
            
            secondary_paddle.input();
            secondary_paddle.update();
            main_ball.paddleCollision(secondary_paddle);
            secondary_paddle.draw();

            powerup_counter++;
          }
          if (powerup_counter >= 1000){
            powerup_counter = 0;
            GameManager::user_have_powerup = false;
            GameManager::double_paddle = false;
          }

          // Check if ball falls down
          if (main_ball.pos_y_ > GameManager::Instance()->kScreenHeight + 50){
            GameManager::selected_scene_ = GameManager::scene_score;
          }
          hud.draw();
        }
        break;
        case(GameManager::scene_score) : {
          ESAT::DrawSetTextFont("fonts/prstart.ttf");
          ESAT::DrawSetFillColor(75, 75, 75, 255);
          ESAT::DrawSetTextSize(50.0f);
          ESAT::DrawText(300.0f, 120.0f, "Game Over");

          ESAT::DrawSetFillColor(255, 255, 0, 255);
          std::string tmp_points = "SCORE " + std::to_string(GameManager::points_);
          ESAT::DrawText(GameManager::Instance()->kScreenWidth / 3 - 50,
            GameManager::Instance()->kScreenHeight / 2,
            tmp_points.c_str());

          ESAT::DrawSetTextFont("fonts/graphicpixel-webfont.ttf");
          ESAT::DrawText(GameManager::Instance()->kScreenWidth / 3 + 150, GameManager::Instance()->kScreenHeight / 2 + 100, "<3");

        }
        break;

      }
      // End of current frame
      ESAT::WindowFrame();
    }
  }
  // Exit Game
  // Free / Clear / Delete resources here

  

  ESAT::WindowDestroy();
  return 0;
}