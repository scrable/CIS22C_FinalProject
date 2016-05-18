#include "RestaurantDatabase.h"
#include "BST.h"

RestaurantDatabase::RestaurantDatabase()
{
    uniqueBSTDatabase = new BST<string>;
}

//run this when we need to write to a file
//this will output ALL of the data structures to a file
void RestaurantDatabase::writeFile()
{
    return;
}

void RestaurantDatabase::readFile()
{
    return;
}

void RestaurantDatabase::addRestaurant()
{
    int data;
    cout << "Add a restaurant to the database" << endl;

    //add placeholder cin to hold the screen
    cin >> data;

    Restaurant rest;
    rest.setName("string");
    uniqueBSTDatabase->insert(rest);
    cout << "root: " << uniqueBSTDatabase->getRoot();

   // cin.get();
    return;
}

void RestaurantDatabase::removeRestaurant()
{
    int data;
    cout << "Remove a restaurant from the database" << endl;

    //add placeholder cin to hold the screen
    cin >> data;

    //cin.get();
    return;
}
