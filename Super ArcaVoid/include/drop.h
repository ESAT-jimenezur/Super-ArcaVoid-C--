/** @brief Drop Manager class declaration
 *
 * @author Modified by Jose Luis
 */


#ifndef __DROP_H__
#define __DROP_H__

#include "object.h"

class Drop : public Object{
public:


  Drop();
  ~Drop(){};

  void init();
  void update();
  void createDrop(int pos_x, int pos_y);
  void fall();

  int size;

};


#endif __DROP_H__