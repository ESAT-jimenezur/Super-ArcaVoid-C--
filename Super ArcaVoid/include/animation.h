/* Animations layer declaration
 *
 * Modified by Jose Luis
 */

#ifndef __ANIMATION_H__
#define __ANIMATION_H__

#include <string>

#include "object.h"



struct vector2{
  int pos_x_;
  int pos_y_;
};

class Animation : public Object{

public:

  void init();

  void animateText(std::string text, vector2 position);

  Animation();
  ~Animation(){};

private:

};

#endif __ANIMATION_H__