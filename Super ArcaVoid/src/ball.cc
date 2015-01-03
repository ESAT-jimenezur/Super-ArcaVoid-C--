/* Default Ball class implementation
 *
 * @author Jose Luis Jimenez Urbano | < ijos@ijos.es > | < @iJos >
 */


#include <stdlib.h>

#include <ESAT/draw.h>
#include <stdio.h>

#include "../include/ball.h"


Ball::Ball(){
  pos_x_ = GameManager::Instance()->kScreenWidth / 2 - kBallSize/2;
  pos_y_ = GameManager::Instance()->kScreenHeight / 1.5f - kBallSize/2;
}

void Ball::init(){
  Object::init(NULL); // We don't need any sprite

  //Yellow ball by default
  red = 255;
  green = 255;
  blue = 0;
  alpha = 255;

  vel_x_ = 50.0f;
  vel_y_ = 100.0f;

  p_ball();
}

void Ball::update(){
  Object::update();

  //Movement -> EULER OR RUNGE KUTTA HERE
  /*
   * @link http://es.wikipedia.org/wiki/M%C3%A9todo_de_Euler
   * @link http://es.wikipedia.org/wiki/M%C3%A9todo_de_Runge-Kutta
   *
   */


  /*
  vel_x_ = 4.0f;
  vel_y_ = 4.0f;
  
  pos_x_ = pos_x_ + vel_x_; // * Delta T;
  pos_y_ = pos_y_ + vel_y_; // * Delta T;
  vel_x_ = vel_x_; // * Delta T;
  vel_y_ = vel_y_; // * Delta T;
  */


  //We should limit position here
  //Horizontal
  if (pos_x_ >= GameManager::Instance()->kScreenWidth - kBallSize/2 || pos_x_ <= 0){
    vel_x_ = -vel_x_;
  }

  //Vertical
  if (pos_y_ <= 0){ //Bottom side margin
    vel_y_ = -vel_y_;
  }


}

void Ball::draw(){
  Object::draw();

  p_ball();
}

void Ball::setBallColor(unsigned char r, unsigned char g, unsigned char b, unsigned char a){
  red   = r;
  green = g;
  blue  = b;
  alpha = a;
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
  
  ESAT::DrawSetFillColor(red, green, blue, alpha);
  ESAT::DrawSetStrokeColor(red, green, blue, alpha);
  ESAT::DrawSolidPath(points, 5, true);

}