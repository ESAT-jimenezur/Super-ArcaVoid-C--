/* Default Game Manager class declaration
 *
 * Modified by Jose Luis
 */

#ifndef __GAME_MANAGER_H__
#define __GAME_MANAGER_H__

#include "../include/game_pad.h"

class GameManager{
public:
  
  const unsigned short int kScreenWidth = 1024;
  const unsigned short int kScreenHeight = 768;

  static const unsigned short int kBrick_width = 71;
  static const unsigned short int kBrick_height = 25;

  static const unsigned short int kBricks_per_line = 14;
  static const unsigned short int kBricks_lines = 8;
  static const unsigned int kBricks_amount = kBricks_per_line * kBricks_lines;
  static const unsigned short int kBricks_vertical_offset = 3;
  static const unsigned short int kBricks_horizontal_offset = 3;

  

  // Singleton instance
  static GameManager *Instance();

  // Game Objects
  // Pads
  GamePad *game_pad1;
  GamePad *game_pad2;

private:
  static GameManager *state;
  GameManager::GameManager();


  void init();
};

#endif __GAME_MANAGER_H__