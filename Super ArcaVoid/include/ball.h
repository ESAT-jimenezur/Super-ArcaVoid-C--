/* Default Ball class declaration
 *
 * @author Jose Luis Jimenez Urbano | < ijos@ijos.es > | < @iJos >
 */


#ifndef __BALL_H__
#define __BALL_H__

#include "object.h"
#include "game_manager.h"

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

private:
  unsigned char red;
  unsigned char green;
  unsigned char blue;
  unsigned char alpha;
  
  //This method creates a pixel ball, without using a sprite
  void p_ball();

};


#endif __BALL_H__