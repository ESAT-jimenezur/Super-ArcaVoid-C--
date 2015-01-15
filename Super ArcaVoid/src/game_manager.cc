/* Default Game Manager class implementation
 *
 * Modified by Jose Luis
 */

#include "../include/game_manager.h"

#include <stdio.h>

GameManager* GameManager::state = NULL;

unsigned int GameManager::kAnimation_position_x;
unsigned int GameManager::kAnimation_position_y;
unsigned int GameManager::points_;

GameManager* GameManager::Instance() {
  //only one instance of this object can be generated
  if (!state) {
    state = new GameManager();
    state->init();
  }
  return state;
}

GameManager::GameManager() {
  kAnimation_position_x = 0;
  kAnimation_position_y = 0;
  points_ = 0;
}


void GameManager::init(){

  // Game Pads init
  game_pad1 = new GamePad();
  game_pad2 = new GamePad(); // We comment this, we should discomment in case we need it
}