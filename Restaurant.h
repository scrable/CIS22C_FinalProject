#ifndef _RESTAURANT_H_
#define _RESTAURANT_H_

#include <iomanip>
#include <ostream>
#include <istream>

using namespace std;

class Restaurant
{
private:
    string name;
    string cuisine;
    string location;
    int openingHour;
    int closingHour;
    int cost;
    double phoneNumber;
    double rating;
public:
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
    void setAll(string name, string cuisine, string location, int openingHour, int closingHour, int cost, double rating, double phoneNumber);

    //for outputting a restaurant
    friend ostream& operator<<(ostream& out, Restaurant& restaurant);

    //for getting a restaurant from a file
    friend istream& operator>>(istream& in, Restaurant& restaurant);

    //for checking if two restaurants are equal
    friend bool operator==(Restaurant r1, Restaurant r2);
};

#endif // _RESTAURANT_H
