#ifndef _RESTAURANT_H_
#define _RESTAURANT_H_

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
     double phoneNumber;
     double rating;
     double cost;
     ///kkk
 public:
     //default constructor
     Restaurant();

     /* getters */

     string getName();
     string getCuisine();
     string getLocation();
     int getOpeningHour();
     int getClosingHour();
     double getPhoneNumber();
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
     void setPhoneNumber(double phoneNumber);

     friend ostream& operator<<(ostream& out, Restaurant& restaurant);

};

 #endif // _RESTAURANT_H
