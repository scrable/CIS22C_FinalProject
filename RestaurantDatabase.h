#ifndef _RESTAURANTDATABASE_H_
#define _RESTAURANTDATABASE_H_

#include "Restaurant.h"
#include "Report.h"

class RestaurantDatabase
{
private:
    //pointer to the uniqueBSTDatabase
    BST<string>* uniqueBSTDatabase;

    //contains a pointer to the secondary key BST
    BST<string>* secondaryBSTDatabase;

    //contains a pointer to the hash table
    HashTable* hashTable;

    //used for holding the name of the input database file
    string inputDatabaseFile;

    //used for holding the name of the output database file
    string outputDatabaseFile;

public:
    RestaurantDatabase();
    RestaurantDatabase(BST<string>* uniqueBSTDatabase, BST<string>* secondaryBSTDatabase, HashTable* hashTable);

    //writes all information to the file
    //user is prompted for file directory and name
    //if no file exists, create a new file
    //this is supposed to be run automatically when the program ends
    //so we will add it to our destructor
    void writeFile();

    //reads a file and creates the data structures from it
    void readFile();

    //sets the input database file name to what the user inputs
    void setInputDatabaseFile(string file);

    //gets the current input database file name
    string getInputDatabaseFile();

    //sets the output database file name to what the user inputs
    void setOutputDatabaseFile(string file);

    //gets the current output database file name
    string getOutputDatabaseFile();

    //adds a restaurant to all 3 databases
    void addRestaurant(Restaurant rest);

    //removes a restaurant from the database
    //searches for a restaurant by name by calling searchByName() from Report.h
    void removeRestaurant(Restaurant r);

    //menu for removing a restaurant
    void removeRestaurantMenu();

    //menu for adding a restaurant
    //provides user with list of items to enter
    void addRestaurantMenu();
};

#endif // RESTAURANTDATABASE_H
