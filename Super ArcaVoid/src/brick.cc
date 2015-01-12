/* Default Brick class implementation
 *
 * @author Jose Luis Jimenez Urbano | < ijos@ijos.es > | < @iJos >
 */

#include <stdlib.h>
#include <stdio.h>

#include <ESAT/draw.h>

#include "../include/brick.h"


Brick::Brick(){

}

void Brick::init(){
  Object::init(NULL);

  //Default Brick Values
  red_ = 255;
  green_ = 255;
  blue_ = 0;
  alpha_ = 255;
}

void Brick::update(){
  Object::update();
}

void Brick::draw(){
  Object::draw();

  p_brick();
}

void Brick::setBrickColor(unsigned char r, unsigned char g, unsigned char b, unsigned char a){
  red_ = r;
  green_ = g;
  blue_ = b;
  alpha_ = a;
}

void Brick::p_brick(){
  float points[] = {
    pos_x_, pos_y_ + height_,
    pos_x_ + width_, pos_y_ + height_,
    pos_x_ + width_, pos_y_,
    pos_x_, pos_y_,
    pos_x_, pos_y_ + height_, // last point connects with the first one
  };

  ESAT::DrawSetFillColor(red_, green_, blue_, alpha_);
  ESAT::DrawSetStrokeColor(red_, green_, green_, green_);
  ESAT::DrawSolidPath(points, 5, true);
}

void Brick::size(int w, int h){
  width_ = w;
  height_ = h;
}

void Brick::setWidth(int w){
  width_ = w;
}

void Brick::setHeight(int h){
  height_ = h;
}

void Brick::position(unsigned int x, unsigned int y){
  pos_x_ = x;
  pos_y_ = y;
}

void Brick::position_x(unsigned int x){
  pos_x_ = x;
}

void Brick::position_y(unsigned int y){
  pos_y_ = y;
}