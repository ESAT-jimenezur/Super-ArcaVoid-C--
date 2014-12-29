/* Default Game Manager class declaration
 *
 * Modified by Jose Luis
 */

#ifndef __GAME_MANAGER_H__
#define __GAME_MANAGER_H__

class GameManager{
public:
  
  const unsigned short int kScreenWidth = 1600;
  const unsigned short int kScreenHeight = 768;
  


  // Singleton instance
  static GameManager *Instance();



private:
  static GameManager *state;
  GameManager::GameManager();


  void init();
};

#endif __GAME_MANAGER_H__