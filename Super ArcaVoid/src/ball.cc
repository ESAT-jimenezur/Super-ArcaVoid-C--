/* Default Ball class implementation
 *
 * @author Jose Luis Jimenez Urbano | < ijos@ijos.es > | < @iJos >
 */


#include <stdlib.h>
#include <stdio.h>

#include <ESAT/draw.h>

#include "../include/ball.h"
#include "../include/animation.h"
#include "../include/random.h"

Ball::Ball(){
  pos_x_ = GameManager::Instance()->kScreenWidth / 2 - kBallSize/2;
  pos_y_ = GameManager::Instance()->kScreenHeight / 1.5f - kBallSize/2;
}

void Ball::init(){
  Object::init(NULL); // We don't need any sprite

  //Yellow ball by default
  red_ = 255;
  green_ = 255;
  blue_ = 0;
  alpha_ = 255;

  vel_x_ = 5.0f;
  vel_y_ = 25.0f;

  collision_with_brick_ = false;
  p_ball();
}

void Ball::update(){
  Object::update();
  wall_collision();
}

void Ball::draw(){
  Object::draw();
  p_ball();
}

void Ball::wall_collision(){
  //Horizontal
  if (pos_x_ >= GameManager::Instance()->kScreenWidth - kBallSize / 2 || pos_x_ <= 0){
    vel_x_ = -vel_x_;
  }

  //Vertical
  if (pos_y_ <= 0){ //Bottom side margin
    vel_y_ = -vel_y_;
  }
}

void Ball::paddleCollision(const Paddle& paddle){

  //Ball collision detection
  if (pos_y_ >= paddle.pos_y_ && pos_x_ >= paddle.pos_x_ && pos_x_ <= paddle.pos_x_ + ESAT::SpriteWidth(paddle.sprite_)){
    if (pos_x_ >= paddle.pos_x_ && pos_x_ <= paddle.pos_x_ + 20 ||
      pos_x_ >= paddle.pos_x_ + (ESAT::SpriteWidth(paddle.sprite_) / 2) && pos_x_ <= paddle.pos_x_ + (ESAT::SpriteWidth(paddle.sprite_)) - 20){
      vel_x_ = -vel_x_;
    }
    vel_y_ = -vel_y_;
  }
  printf("%f\n", pos_x_);
}

void Ball::brickCollision(Brick* bricks){
  for (int i = 0; i < GameManager::kBricks_amount; ++i){
    if (bricks[i].enabled_){
      if ((pos_y_ > bricks[i].pos_y_ && pos_y_ < bricks[i].pos_y_ + bricks[i].height_) &&
        (pos_x_ > bricks[i].pos_x_ && pos_x_ < bricks[i].pos_x_ + bricks[i].width_)){
        bricks[i].enabled_ = false;
        vel_y_ = -vel_y_;

        //Add points here
        GameManager::points_ += 100;
        GameManager::destroyed_bricks_++;
        collision_with_brick_ = true;
        GameManager::kAnimation_position_x = bricks[i].pos_x_;
        GameManager::kAnimation_position_y = bricks[i].pos_y_;

        // Generate random objects
        int rand = Random(0, 100);
        if (rand < 100){
          // Here we should implement the extra code for the exam
          // 25 % prob drop powerup + aditional temporal effect

          // Set the drops to 0, we don't want to have 2 drops at the same time
          if (!GameManager::is_dropping && !GameManager::drop_is_falling && !GameManager::user_have_powerup){
            GameManager::is_dropping = true;
            GameManager::drop_is_falling = true;
          }

        }
        // We should add a delay here if last cube to score screen
        // Availiable in the next lib version
        if (GameManager::destroyed_bricks_ >= GameManager::kBricks_amount){
          GameManager::selected_scene_ = GameManager::scene_score;
        }

      }
    }
    
  }
}

void Ball::setBallColor(unsigned char r, unsigned char g, unsigned char b, unsigned char a){
  red_   = r;
  green_ = g;
  blue_  = b;
  alpha_ = a;
}

void Ball::p_ball(){
  //Ball size kBallSize constant
  
  float points[] = {
    pos_x_ - kBallSize/2, pos_y_ + kBallSize/2,
    pos_x_ + kBallSize/2, pos_y_ + kBallSize/2,
    pos_x_ + kBallSize/2, pos_y_ - kBallSize/2,
    pos_x_ - kBallSize/2, pos_y_ - kBallSize/2,
    pos_x_ - kBallSize/2, pos_y_ + kBallSize/2, // last point connects with the first one
  };
  ESAT::DrawSetFillColor(red_, green_, blue_, alpha_);
  ESAT::DrawSetStrokeColor(red_, green_, green_, green_);
  ESAT::DrawSolidPath(points, 5, true);
}