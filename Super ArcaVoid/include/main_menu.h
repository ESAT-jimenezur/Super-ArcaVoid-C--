/* Default Main Menu class declaration
 *
 * Jose Luis
 */

#ifndef __MAIN_MENU__
#define __MAIN_MENU__

class MainMenu{
public:

  void input();

  /* @brief Show the menu on screen
   *
   */
  void showMenu();

  MainMenu();
  ~MainMenu(){};


  unsigned int hovered_menu_;
};

#endif __MAIN_MENU__