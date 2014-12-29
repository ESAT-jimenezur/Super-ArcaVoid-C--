/* Default Game Manager class implementation
 *
 * Modified by Jose Luis
 */

#include "../include/game_manager.h"

#include <stdio.h>

GameManager* GameManager::state = NULL;

GameManager* GameManager::Instance() {
  //only one instance of this object can be generated
  if (!state) {
    state = new GameManager();
    state->init();
  }
  return state;
}

GameManager::GameManager() {

}


void GameManager::init(){

}