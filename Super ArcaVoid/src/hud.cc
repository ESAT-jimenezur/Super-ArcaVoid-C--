/* Animations layer implementation
*
* @author Jose Luis Jimenez Urbano | < ijos@ijos.es > | < @iJos >
*/

#include <stdlib.h>

#include "../include/hud.h"
#include <ESAT/draw.h>
#include "../include/game_manager.h"

Hud::Hud(){

}

void Hud::init(){
  Object::init(NULL);
}

void Hud::draw(){
  Object::draw();
  drawHUD();
}

void Hud::drawHUD(){

  //SCORE
  ESAT::DrawSetTextFont("fonts/prstart.ttf");
  ESAT::DrawSetFillColor(51, 51, 51, 255);
  ESAT::DrawSetTextSize(50.0f);
  //Temporary string from actual points
  std::string tmp_points = "SCORE " + std::to_string(GameManager::points_);
  ESAT::DrawText(GameManager::Instance()->kScreenWidth / 16, 
    GameManager::Instance()->kScreenHeight - 100, 
    tmp_points.c_str());
}