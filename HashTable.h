#ifndef _HASHTABLE_H_
#define _HASHTABLE_H_

#include "Restaurant.h"
#include <iostream>
#include <cstdlib>
#include <fstream>

class HashTable
{

public:
    HashTable();

    ~HashTable();
    //Destructor

    //returns the hash value for the given key
    //the hash value is the sum of
    //the ASCII values of each character % the table size
    int hash(string key);

    //inserts a new item into the table
    //calls the hash function on the key title to determine the correct bucket
    void addItem(Restaurant rest);

    //removes the item with the given key
    void removeItem(Restaurant r);

    //outputs the current hash table to a file
    void printTableToFile(ofstream &fout);

    //Prints all items stored at a single bucket
    void printBucket(int index);

    void printTable();

    //returns a specific restaurantin a specific bucket
    //for the remove function
    Restaurant getRestaurant(int num, int index);

    //Searches for a restaurant in the table using the key entered by the user
    //returns the index under which the restaurant is stored
    //returns -1 if the restaurant is not found
    int findRestaurant(string key);

    //need a way to get table size for looping
    int getTableSize();


private:

    struct Node
    {
        Restaurant rest;
        Node* next;
        Node(): rest(), next(NULL) {}
        Node(Restaurant newRest): rest(newRest), next(NULL) {}
    };

    typedef struct Node* Nodeptr;

    static const int TABLE_SIZE = 60;
    Nodeptr Table[TABLE_SIZE];

};

#endif /* HASHTABLE_H_ */
