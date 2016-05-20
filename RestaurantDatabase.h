#ifndef _RESTAURANTDATABASE_H
#define _RESTAURANTDATABASE_H

#include "Restaurant.h"
#include "Report.h"
#include <string>


using namespace std;

class RestaurantDatabase
{
private:
    //pointer to the uniqueBSTDatabase
    BST<string>* uniqueBSTDatabase;

    //contains a pointer to the secondary key BST
    BST<string>* secondaryBSTDatabase;

public:
    RestaurantDatabase();
    RestaurantDatabase(BST<string>* uniqueBSTDatabase, BST<string>* secondaryBSTDatabase);
    //writes all information to the file
    //user is prompted for file directory and name
    //if no file exists, create a new file
    void writeFile();

    //reads a file and creates the data structures from it
    void readFile();

    //adds a restaurant to the database
    //need to add all restaurant members here in the function call
    void addRestaurant(string name, string cuisine, string location, int openingHour, int closingHour, double cost, double rating, double phoneNumber);

    //removes a restaurant from the database
    //searches for a restaurant by name by calling searchByName() from Report.h
    void removeRestaurant();

    //menu for adding a restaurant
    //provides user with list of items to enter
    void addRestaurantMenu();
};

#endif // RESTAURANTDATABASE_H
