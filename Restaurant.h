#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <iostream>

using namespace std;

class Restaurant
{
private:
	string name;
	string cuisine;
	int openhour;
	int closehour;
	double rating;
	string location;
	double cost;

public:
	Restaurant() : name("default"), cuisine("default"), openhour(0), closehour(0), rating(0), location("default"), cost(0) {}
	string getName();
	string getCuisine();
	int getOpenhour();
	int getClosehour();
	double getRating();
	string getLocation();
	double getCost();
};
