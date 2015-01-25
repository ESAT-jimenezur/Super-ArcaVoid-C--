/** @brief Default Object class declaration
 * From PONG.h
 * 
 * @author Modified by Jose Luis
 */


#ifndef __OBJECT_H__
#define __OBJECT_H__

#include <ESAT/sprite.h>


class Object{

public:
  float pos_x_;
  float pos_y_;

  int id_;

  float accel_x_;
  float accel_y_;

  float vel_x_;
  float vel_y_;

  float dt = 0.2f;

  ESAT::SpriteHandle sprite_;

  bool enabled_;

  bool collisionable_;

  float width_;
  float height_;

  Object();
  ~Object();

  void init(const char* sprite_name);
  void input();
  void update();
  void draw();

  /** @brief Check if the object is colliding right now with the referenced object
   *
   * @param Object& (reference)
   */
  bool isColliding(const Object& other);

private:
  Object(const Object& other){}

protected:
  static int object_counter_;

};

#endif __OBJECT_H__