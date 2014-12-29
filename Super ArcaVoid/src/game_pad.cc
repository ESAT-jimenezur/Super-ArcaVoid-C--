/*  Default Game Padd class declaration
 *
 */


#include "../include/game_pad.h"


GamePad::GamePad() {
  key_up_press = false;
  key_down_press = false;
  key_right_press = false;
  key_left_press = false;
  key_use_press = false;
  key_menu_press = false;
  key_pause_press = false;
  key_enter_press = false;
}

void GamePad::detectPulsations() {
  //key pulsations
  if (ESAT::IsKeyDown(kKeyUp)) key_up_press = true;
  else if (ESAT::IsKeyDown(kKeyDown)) key_down_press = true;
  
  if (ESAT::IsKeyDown(kKeyRight)) key_right_press = true;
  else if (ESAT::IsKeyDown(kKeyLeft)) key_left_press = true;

  if (ESAT::IsKeyDown(kKeyUse)) key_use_press = true;
  if (ESAT::IsKeyDown(kKeyMenu)) key_menu_press = true;
  if (ESAT::IsKeyDown(kKeyPause)) key_pause_press = true;
  if (ESAT::IsKeyDown(kNumOneDown)) key_num_one_press = true;
  if (ESAT::IsKeyDown(kNumTwoDown)) key_num_two_press = true;
  if (ESAT::IsKeyDown(kNumThreeDown)) key_num_three_press = true;
  if (ESAT::IsSpecialKeyDown(ESAT::kSpecialKey_Enter)) key_enter_press = true;
}

void GamePad::restartPulsations() {
  key_up_press = false;
  key_down_press = false;
  key_right_press = false;
  key_left_press = false;
  key_use_press = false;
  key_menu_press = false;
  key_pause_press = false;
  key_enter_press = false;
}