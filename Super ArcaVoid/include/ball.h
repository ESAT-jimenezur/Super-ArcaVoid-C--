/* @brief Default Ball class declaration
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
const unsigned char kBallSize = 5;

class Ball : public Object{

public:

  Ball();
  ~Ball(){};


  void init();
  void update();
  void draw();
  

  /* @brief Method to set the color of the ball (RGBA)
   *
   * @param r (red)
   * @param g (green)
   * @param b (blue)
   * @param a (alpha)
   */
  void setBallColor(unsigned char r, unsigned char g, unsigned char b, unsigned char a);

  /* @brief Checks if exist a collision with the referenced paddle
   *
   * @param Paddle& main_paddle (reference)
   */
  void paddleCollision(const Paddle& main_paddle);

  /* @brief Checks if exist a collision with the referenced brick/s
   *
   * @param Brick& bricks (reference)
   */
  void brickCollision(Brick* bricks); // Should we use const here?

  bool collision_with_brick_ = false;

private:
  unsigned char red_;
  unsigned char green_;
  unsigned char blue_;
  unsigned char alpha_;
  
  ///This method creates a pixel ball, without using a sprite
  void p_ball();

  

};


#endif __BALL_H__