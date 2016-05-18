#ifndef _RESTAURANT_H
#define _RESTAURANT_H

//#include "Restaurant.h"
#include <string>

using namespace std;

 class Restaurant
 {
 private:
     //list attributes for each restaurant here
     //ex. name, cuisine, location, etc
     string name;
 public:
     Restaurant();
     string getName();
     string getCuisine();
     int getOpenhour();
     void setName(string n);
};

 #endif // _RESTAURANT_H
