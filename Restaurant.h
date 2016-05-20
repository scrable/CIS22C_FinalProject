#ifndef _RESTAURANT_H
#define _RESTAURANT_H

#include <string>
#include <iomanip>
#include <ostream>

using namespace std;

 class Restaurant
{
 private:
     //list attributes for each restaurant here
     //ex. name, cuisine, location, etc
     string name;
     string cuisine;
     string location;
     int openingHour;
     int closingHour;
     int phoneNumber;
     double rating;
     double cost;
 public:
     //default constructor
     Restaurant();

     /* getters */
     string getName();
     string getCuisine();
     string getLocation();
     int getOpeningHour();
     int getClosingHour();
     int getPhoneNumber();
     double getRating();
     double getCost();

     /* setters */

     void setName(string name);
     void setCuisine(string cuisine);
     void setLocation(string location);
     void setOpeningHour(int openingHour);
     void setClosingHour(int closingHour);
     void setRating(double rating);
     void setCost(double cost);
     void setPhoneNumber(int phoneNumber);

     friend ostream& operator<<(ostream& out, Restaurant& restaurant);

};

 #endif // _RESTAURANT_H
