/** @brief HUD layer declaration
 *
 * @author Modified by Jose Luis
 */

#ifndef __HUD_H__
#define __HUD_H__

#include <string>

#include "object.h"

class Hud : public Object{

public:

  void init();
  void draw();
  
  /** @brief Draws the HUD on screen
   *
   */
  void drawHUD();

  Hud();
  ~Hud(){};

private:

};

#endif __HUD_H__