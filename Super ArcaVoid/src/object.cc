/* Default Object class implementation
 * From PONG.h
 *
 * Modified by Jose Luis
 */

#include <stdlib.h>
#include <stdio.h>

#include "../include/object.h"

int Object::object_counter_ = 0;

Object::Object(){
  pos_x_ = 0.0f;
  pos_y_ = 0.0f;

  id_ = -1;

  accel_x_ = 0.0f;
  accel_y_ = 0.0f;

  vel_x_ = 0.0f;
  vel_y_ = 0.0f;

  enabled_ = true;

  collisionable_ = false;

  height_ = 0.0f;
  width_ = 0.0f;
}

Object::~Object(){
  if (sprite_ > 0){
    ESAT::SpriteRelease(sprite_);
  }
}



void Object::init(const char* sprite_name){
  id_ = object_counter_;
  ++object_counter_;

  if (sprite_name == NULL){
    width_ = 0.0f;
    height_ = 0.0f;
  }
  else{
    sprite_ = ESAT::SpriteFromFile(sprite_name);
    width_ = ESAT::SpriteWidth(sprite_);
    height_ = ESAT::SpriteHeight(sprite_);
  }

}

void Object::input(){};

void Object::update(){
  //Move the object by its acceleration
  if (enabled_){
    vel_x_ += accel_x_ * dt;
    vel_y_ += accel_y_ * dt;

    pos_x_ += vel_x_ * dt;
    pos_y_ += vel_y_ * dt;
  }
}

void Object::draw(){
  if (enabled_ && (sprite_ > 0)){
    ESAT::DrawSprite(sprite_, pos_x_, pos_y_);
  }
}



bool Object::isColliding(const Object& other){
  if (collisionable_ && other.collisionable_){

    if ((other.pos_x_ >= pos_x_) && (other.pos_x_ <= pos_x_ + width_)){
      if ((other.pos_y_ >= pos_y_) && (other.pos_y_ <= pos_y_ + height_)){
        return true;
      }
    }

    if ((other.pos_x_ + other.width_ >= pos_x_) && (other.pos_x_ + other.width_ <= pos_x_ + width_)){
      if ((other.pos_y_ + other.height_ >= pos_y_) && (other.pos_y_ + height_ <= pos_y_ + height_)){
        return true;
      }
    }

    return false;

  }
  return false;
}

