/* Default Paddle class implementation
 * From PADDLE.h
 *
 * Modified by Jose Luis
 */

#include "../include/drop.h"
#include <stdio.h>

#include <ESAT/draw.h>


Drop::Drop(){

}

void Drop::init(){
  //Object::init(NULL);
  size = 25;
}

void Drop::update(){
  //Object::update();
}

void Drop::createDrop(int pos_x, int pos_y){
  pos_x_ = pos_x;
  pos_y_ = pos_y;

  float points[] = {
    pos_x, pos_y + size,
    pos_x + size, pos_y + size,
    pos_x + size, pos_y,
    pos_x, pos_y,
    pos_x, pos_y + size, // last point connects with the first one
  };

  ESAT::DrawSetFillColor(0, 0, 255, 255);
  ESAT::DrawSetStrokeColor(0, 0, 255, 255);
  ESAT::DrawSolidPath(points, 5, true);
}

void Drop::fall(){
  pos_y_ += 4;
};