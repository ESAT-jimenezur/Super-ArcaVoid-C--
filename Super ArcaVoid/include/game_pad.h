/*  Default Game Padd class implementation
 *
 */

#ifndef __GAME_PADD_H__
#define __GAME_PADD_H__

#include <ESAT/input.h>
/**
* @brief Detect pulsation in the keyboard
*/
class GamePad {
public:
  //constants key
  const char kKeyUp = 'w';
  const char kKeyDown = 's';
  const char kKeyRight = 'd';
  const char kKeyLeft = 'a';
  const char kKeyUse = 'e';
  const char kKeyMenu = 'i';
  const char kKeyPause = 'p';
  const char kNumOneDown = '1';
  const char kNumTwoDown = '2';
  const char kNumThreeDown = '3';
  
  //Mouse Position
  int mouse_position_x_;
  int mouse_position_y_;
  int mouse_wheel_x_;
  int mouse_wheel_y_;

  //keys pressed
  bool key_up_press;
  bool key_down_press;
  bool key_right_press;
  bool key_left_press;
  bool key_use_press;
  bool key_menu_press;
  bool key_pause_press;
  bool key_enter_press;
  bool key_num_one_press;
  bool key_num_two_press;
  bool key_num_three_press;
  //constructor
  GamePad();

  /** @brief Detect the keys that the players puss
   *
   */
  void detectPulsations();
  /** @brief Restarts pulsations of the player
   *
   */
  void restartPulsations(); 

  /** @brief This method updates X and Y Mouse Data
   *
   */
  void mouseDetection();
  
  /* @brief Returns X mouse Position
   *
   */
  int getMousePositionX();

  /* @brief Returns Y mouse Position
   *
   */
  int getMousePositionY();

  /* @brief Returns X mouse Wheel Position
   *
   */
  int getMouseWheelX();

  /* @brief Returns Y mouse Wheel Position
   *
   */
  int getMouseWheelY();
};

#endif __GAME_PADD_H__



