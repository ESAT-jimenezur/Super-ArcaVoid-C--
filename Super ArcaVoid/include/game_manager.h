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