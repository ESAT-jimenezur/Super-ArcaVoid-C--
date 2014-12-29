/* Default Paddle class declaration
 * From PADDLE.h
 *
 * Modified by Jose Luis
 */


#ifndef __PADDLE_H__
#define __PADDLE_H__

#include "object.h"

const float kPaddleMaxVelocity = 0.005f;

class Paddle : public Object{

public:

  float desired_x_;

  void init(const char* sprite_name, float desired_x);
  void update();

private:


};


#endif __PADDLE_H__