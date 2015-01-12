/* Default Brick class declaration
 *
 * @author Jose Luis Jimenez Urbano | < ijos@ijos.es > | < @iJos >
 */

#ifndef __BRICK_H__
#define __BRICK_H__

#include "object.h"

class Brick : public Object{
public:
  Brick();
  ~Brick(){};


  void init();
  //Maybe, we can implement here later the posibility of move the bricks
  void update();
  void draw();

  void setBrickColor(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
  void setBrickPosition(unsigned int pos_x, unsigned int pos_y);

  ///This method creates a pixel brick, without using a sprite
  void p_brick();

  void size(int w, int h);
  void setWidth(int w);
  void setHeight(int h);

  void position(unsigned int x, unsigned int y);
  void position_x(unsigned int x);
  void position_y(unsigned int y);

private:
  unsigned char red_;
  unsigned char green_;
  unsigned char blue_;
  unsigned char alpha_;
};

#endif __BRICK_H__