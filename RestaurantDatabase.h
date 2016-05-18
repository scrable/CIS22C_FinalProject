#ifndef _RESTAURANTDATABASE_H
#define _RESTAURANTDATABASE_H

#include "Restaurant.h"
#include "Report.h"
//#include "BST.h"
#include <string>


using namespace std;

class RestaurantDatabase// : public BST
{
private:
    BST<string>* uniqueBSTDatabase;
public:
    RestaurantDatabase();
    //writes all information to the file
    //user is prompted for file directory and name
    //if no file exists, create a new file
    void writeFile();

    //reads a file and creates the data structures from it
    void readFile();

    //adds a restaurant to the database
    void addRestaurant();

    //removes a restaurant from the database
    //searches for a restaurant by name by calling searchByName() from Report.h
    void removeRestaurant();
};

#endif // RESTAURANTDATABASE_H
