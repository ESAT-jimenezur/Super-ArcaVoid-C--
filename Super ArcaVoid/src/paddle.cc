/* Default Paddle class implementation
 * From PADDLE.h
 *
 * Modified by Jose Luis
 */

#include "../include/paddle.h"


void Paddle::init(const char* sprite_name, float desired_x){
  Object::init(sprite_name);

  desired_x_ = desired_x;
}

void Paddle::update() {
  //Calling parent update method
  Object::update();

  if (vel_y_ > kPaddleMaxVelocity){
    vel_y_ = kPaddleMaxVelocity;
  }
  else if (vel_y_ < -kPaddleMaxVelocity){
    vel_y_ = -kPaddleMaxVelocity;
  }

  //Limit position
  if (pos_y_ < 0.0f){
    pos_y_ = 0.0f;
  }
  else if (pos_y_ + height_ > 768){
    pos_y_ = 768 - height_;
  }

  //Fix x to desired X position
  pos_x_ = desired_x_;
}