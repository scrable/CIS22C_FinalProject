#ifndef _REPORT_H
#define _REPORT_H

/*
    This class will be for our reporting
    This includes the Search, List, and Statistics portions mentioned in the Menu Requirements
*/

#include "BST.h"
#include <string>

class Report
{
private:
    BST<string>* uniqueBSTDatabase;
    BST<string>* secondaryBSTDatabase;

public:
    Report();
    Report(BST<string>* uniqueBSTdatabase, BST<string>* secondaryBSTDatabase);

    /* Searching functions */

    //we need a main menu to get user input for searching
    void searchMainMenu();

    //searches restaurants by name
    //this is the primary key
    void searchByName();

    //searches restaurants by cuisine type
    //this is the secondary key
    void searchByCuisine();

    /* List functions */

    //we also need a main menu for the listings
    void listMainMenu();

    //lists entire restaurant database unsorted
    void listUnsorted();

    //lists restaurant databaase sorted by name
    //this is the primary key
    void listSortedByName();

    //lists restaurant database sorted by cuisine
    //this is the secondary key
    void listSortedByCuisine();

    /* Statistics functions */

    //we need a main menu for the statistics
    void statisticsMainMenu();

    //lists the number of restaurants per cuisine type
    //ex: 2 mexican 3 chinese 5 thai etc
    void restaurantsPerCuisine();

    //lists restaurants with the best ratings
    //for this, we should have some sort of parameter that defines
    //how many restaurants to show, and what the best rating is
    //should we show restaurants only at 5? all above 4.5?
    //ask user for the lowest rating they will accept? - add parameter to function definition if yes
    void restaurantsBestRating();

    //lists the restaurants that are affordable
    //the user will input the dollar amount they will be willing to pay for food
    //show all restaurants that have that price range or less than that price range
    void affordableRestaurants();

};

#endif // _REPORT_H
