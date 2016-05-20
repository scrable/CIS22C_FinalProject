#include "Restaurant.h"

Restaurant::Restaurant()
{
    name = "default name";
    cuisine = "default cuisine";
    location = "default location";
    openingHour = 0;
    closingHour = 0;
    phoneNumber = 0.0;
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

void Restaurant::setName(string n)
{
    name = n;
}

void Restaurant::setCuisine(string c)
{
    cuisine = c;
}

void Restaurant::setLocation(string l)
{
    location = l;
}

void Restaurant::setOpeningHour(int oh)
{
    openingHour = oh;
}

void Restaurant::setClosingHour(int ch)
{
    closingHour = ch;
}

void Restaurant::setRating(double r)
{
    rating = r;
}

void Restaurant::setCost(double c)
{
    cost = c;
}

void Restaurant::setPhoneNumber(double phoneNumb)
{
    phoneNumber = phoneNumb;
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




