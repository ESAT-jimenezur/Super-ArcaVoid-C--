/* Default Paddle class implementation
 * From PADDLE.h
 *
 * Modified by Jose Luis
 */

#include "../include/paddle.h"
#include <stdio.h>

Paddle::Paddle(){
  
}

void Paddle::init(const char* sprite_name){
  Object::init(sprite_name);
}


void Paddle::input(){
  Object::input();

  GameManager::Instance()->game_pad1->detectPulsations();

  // If press
  // Solucion temporal al movimiento... mas adelante se mejorara
  if (GameManager::Instance()->game_pad1->key_left_press){
    vel_x_ -= 20;
  }
  else if (GameManager::Instance()->game_pad1->key_right_press){
    vel_x_ += 20;
  }
  
  GameManager::Instance()->game_pad1->restartPulsations();
};

void Paddle::update() {
  //Calling parent update method
  Object::update();

  if (vel_x_ > kPaddleMaxVelocity){
    vel_x_ = kPaddleMaxVelocity;
  }
  else if (vel_x_ < -kPaddleMaxVelocity){
    vel_x_ = -kPaddleMaxVelocity;
  }

  //Limit position
  if (pos_x_ < 0.0f){
    pos_x_ = 0.0f;
  }
  else if (pos_x_ + width_ >  GameManager::Instance()->kScreenWidth){
    pos_x_ = GameManager::Instance()->kScreenWidth - width_;
  }

  //Fix Y to desired Y position
  //pos_y_ = desired_y_;
}