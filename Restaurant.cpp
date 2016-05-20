#include "Restaurant.h"

Restaurant::Restaurant()
{
    name = "default name";
    cuisine = "default cuisine";
    location = "default location";
    openingHour = 0;
    closingHour = 0;
    rating = 0.0;
    cost = 0.0;
}

string Restaurant::getName()
{
    return name;
}

string Restaurant::getCuisine()
{
    return cuisine;
}

string Restaurant::getLocation()
{
    return location;
}

int Restaurant::getOpeningHour()
{
    return openingHour;
}

int Restaurant::getClosingHour()
{
    return closingHour;
}

double Restaurant::getRating()
{
    return rating;
}

double Restaurant::getCost()
{
    return cost;
}

double Restaurant::getPhoneNumber()
{
    return phoneNumber;
}

void Restaurant::setName(string name)
{
    this->name = name;
}

void Restaurant::setCuisine(string cuisine)
{
    this->cuisine = cuisine;
}

void Restaurant::setLocation(string location)
{
    this->location = location;
}

void Restaurant::setOpeningHour(int openingHour)
{
    this->openingHour = openingHour;
}

void Restaurant::setClosingHour(int closingHour)
{
    this->closingHour = closingHour;
}

void Restaurant::setRating(double rating)
{
    this->rating = rating;
}

void Restaurant::setCost(double cost)
{
    this->cost = cost;
}

void Restaurant::setPhoneNumber(double phoneNumber)
{
    this->phoneNumber = phoneNumber;
}


ostream& operator<<(ostream& out, Restaurant& restaurant)
{
	out << fixed << setprecision(1);			// makes doubles round to one digit
	out << "Name: " << restaurant.getName() << endl;
	out << "Cuisine: " << restaurant.getCuisine() << endl;
	out << "Location: " << restaurant.getLocation() << endl;
	out << "Opening Hour: " << restaurant.getOpeningHour() << endl;
	out << "Closing Hour: " << restaurant.getClosingHour() << endl;
	out << "Cost Consideration: " << restaurant.getCost() << endl;
	out << "Rating:" << restaurant.getRating() << endl;
	out << "Phone Number: " << restaurant.getPhoneNumber() << endl;
	return out;
}




