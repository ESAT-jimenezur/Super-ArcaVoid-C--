/* Default Main Menu class implementation
 *
 * Jose Luis
 */

#include <stdio.h>

#include <ESAT/draw.h>

#include "../include/main_menu.h"
#include "../include/game_manager.h"

MainMenu::MainMenu(){

}

void MainMenu::input(){
  GameManager::Instance()->game_pad1->detectPulsations();
  

  // Play
  if (GameManager::Instance()->game_pad1->getMousePositionX() >= 430 && GameManager::Instance()->game_pad1->getMousePositionX() <= 600 && 
    GameManager::Instance()->game_pad1->getMousePositionY() >= 340 && GameManager::Instance()->game_pad1->getMousePositionY() <= 400){
    hovered_menu_ = 1;
  }

  // Exit
  if (GameManager::Instance()->game_pad1->getMousePositionX() >= 430 && GameManager::Instance()->game_pad1->getMousePositionX() <= 600 &&
    GameManager::Instance()->game_pad1->getMousePositionY() >= 440 && GameManager::Instance()->game_pad1->getMousePositionY() <= 500){
    hovered_menu_ = 3;
  }


  if (ESAT::MouseButtonDown(1)){
    if (hovered_menu_ == 1){
      GameManager::selected_scene_ = GameManager::scene_game;
    }
    else if (hovered_menu_ == 3){
      GameManager::should_exit = 1;
    }
  }

  


  GameManager::Instance()->game_pad1->restartPulsations();
}

void MainMenu::showMenu(){

  // Title
  ESAT::DrawSetTextFont("fonts/prstart.ttf");
  ESAT::DrawSetFillColor(75, 75, 75, 255);
  ESAT::DrawSetTextSize(50.0f);
  ESAT::DrawText(75.0f, 120.0f, "Super ArcaVoid C++");

  // Menu options
  ESAT::DrawSetTextSize(25.0f);

  if (hovered_menu_ == 1){
    ESAT::DrawSetFillColor(150, 150, 150, 255);
  }else{
    ESAT::DrawSetFillColor(50, 50, 50, 255);
  }
  ESAT::DrawText(GameManager::Instance()->kScreenWidth / 2 - 50, GameManager::Instance()->kScreenHeight / 2, "Play");

  if (hovered_menu_ == 3){
    ESAT::DrawSetFillColor(150, 150, 150, 255);
  }
  else{
    ESAT::DrawSetFillColor(50, 50, 50, 255);
  }
  ESAT::DrawText(GameManager::Instance()->kScreenWidth / 2 - 50, GameManager::Instance()->kScreenHeight / 2 + 100, "Exit");
}