#ifndef _MAINMENU_H
#define _MAINMENU_H

#include "Report.h"
#include "RestaurantDatabase.h"

class MainMenu
{
private:
    Report report;
    RestaurantDatabase* restaurantDatabase;

    //contains a pointer to the unique key BST
    BST<string>* uniqueBSTDatabase;
public:
    //constructor
    MainMenu();

    //destructor
    ~MainMenu();

    //displays the first main menu
    void showMainMenu();
};

#endif // MAINMENU_H
