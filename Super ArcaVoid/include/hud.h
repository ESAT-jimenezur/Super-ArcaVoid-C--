/* HUD layer declaration
 *
 * Modified by Jose Luis
 */

#ifndef __HUD_H__
#define __HUD_H__

#include <string>

#include "object.h"

class Hud : public Object{

public:

  void init();
  void draw();
  
  void drawHUD();

  Hud();
  ~Hud(){};

private:

};

#endif __HUD_H__