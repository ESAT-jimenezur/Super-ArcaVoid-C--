/* Default Ball class declaration
 *
 * @author Jose Luis Jimenez Urbano | < ijos@ijos.es > | < @iJos >
 */


#ifndef __BALL_H__
#define __BALL_H__

#include "object.h"
#include "game_manager.h"
#include "paddle.h"
#include "brick.h"

const float kBallMaxVelocity = 4.0f;
const unsigned char kBallSize = 4;

class Ball : public Object{

public:

  Ball();
  ~Ball(){};


  void init();
  void update();
  void draw();

  void setBallColor(unsigned char r, unsigned char g, unsigned char b, unsigned char a);

  void paddleCollision(const Paddle& main_paddle);
  void brickCollision(Brick* bricks); // Should we use const here?

private:
  unsigned char red_;
  unsigned char green_;
  unsigned char blue_;
  unsigned char alpha_;
  
  ///This method creates a pixel ball, without using a sprite
  void p_ball();

  

};


#endif __BALL_H__