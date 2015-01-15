/* Animations layer implementation
 *
 * @author Jose Luis Jimenez Urbano | < ijos@ijos.es > | < @iJos >
 */

#include <stdlib.h>

#include "../include/animation.h"
#include <ESAT/draw.h>

Animation::Animation(){

}

void Animation::init(){
  Object::init(NULL);
}

void Animation::animateText(std::string text, vector2 position){
  ESAT::DrawSetTextFont("fonts/prstart.ttf");
  ESAT::DrawSetFillColor(rand() % 255, rand() % 255, rand() % 255, 255);
  ESAT::DrawSetTextSize(20.0f);
  ESAT::DrawText(position.pos_x_, position.pos_y_, text.c_str());
}
