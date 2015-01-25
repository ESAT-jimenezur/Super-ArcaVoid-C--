/** @brief Default Brick class declaration
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

  /** @brief Method to set the color of the brick (RGBA)
   *
   * @param r (red)
   * @param g (green)
   * @param b (blue)
   * @param a (alpha)
   */
  void setBrickColor(unsigned char r, unsigned char g, unsigned char b, unsigned char a);

  /** @brief Method to set the position of the brick
   *
   * @param pos_x
   * @param pos_y
   */
  void setBrickPosition(unsigned int pos_x, unsigned int pos_y);

  /// This method creates a pixel brick, without using a sprite
  void p_brick();

  /** @brief Set the size of the brick
   *
   * @param w (width)
   * @param h (height)
   */
  void size(int w, int h);

  /** @brief Set the width of the brick
   *
   * @param w (width)
   */
  void setWidth(int w);

  /** @brief Set the height of the brick
   *
   * @param h (height)
   */
  void setHeight(int h);

  
  /** @brief Set the position of the brick
   *
   * @param x
   * @param y
   */
  void position(unsigned int x, unsigned int y);

  /** @brief Set the X position of the brick
   *
   * @param x
   */
  void position_x(unsigned int x);

  /** @brief Set the Y position of the brick
   *
   * @param y
   */
  void position_y(unsigned int y);

private:
  unsigned char red_;
  unsigned char green_;
  unsigned char blue_;
  unsigned char alpha_;
};

#endif __BRICK_H__