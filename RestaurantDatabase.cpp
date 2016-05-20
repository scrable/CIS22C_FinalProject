#include "RestaurantDatabase.h"
#include "BST.h"

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif // _WIN32

RestaurantDatabase::RestaurantDatabase()
{
    //uniqueBSTDatabase = new BST<string>;
    //secondaryBSTDatabase = new BST<string>;
}

RestaurantDatabase::RestaurantDatabase(BST<string>* uniqueBSTDatabase, BST<string>* secondaryBSTDatabase)
{
    this->uniqueBSTDatabase = uniqueBSTDatabase;
    this->secondaryBSTDatabase = secondaryBSTDatabase;
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

void RestaurantDatabase::addRestaurant(string name, string cuisine, string location, int openingHour, int closingHour, double cost, double rating, double phoneNumber)
{
    //this is only an example of the usage for our BST
    //insert currently ONLY fucntions for the name parameter
    //until i or someone else updates all the BST functions to work with an operator overload
    Restaurant rest;
    rest.setCost(cost);
    rest.setRating(rating);
    rest.setName(name);
    rest.setClosingHour(closingHour);
    rest.setOpeningHour(openingHour);
    rest.setLocation(location);
    rest.setCuisine(cuisine);

    //insert the restaurant to the hash database
    //hash->insert(rest);

    uniqueBSTDatabase->insert(name, phoneNumber);
    secondaryBSTDatabase->insert(cuisine, phoneNumber);

    system(CLEAR);
    cout << "\n\n\n\t\tRestaurant added successfully!\n\t\tPress any key to continue." << endl;
    cin.ignore(1000, '\n');
    //cin.get();
    return;
}

void RestaurantDatabase::removeRestaurant()
{
    system(CLEAR);
    cout << "\n\t\tPress any key to continue." << endl;
    cin.ignore(1000, '\n');
    cin.get();
    return;
}

void RestaurantDatabase::addRestaurantMenu()
{
    bool done = false;

    //declare temp variables
    string name;
    string cuisine;
    string location;
    int openingHour;
    int closingHour;
    double phoneNumber;
    double rating;
    double cost;
    char alwaysOpen;

    system(CLEAR);

    //get info for the restaurant
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "What is the name of the restaurant? ";
    getline(cin, name);
    while (!done)
    {
        cout << "What is the cost consideration of the restaurant?\nPlease enter a number 0-5: ";
        cin >> cost;
        if (cin.fail() || cost < 0 || cost > 5)
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid response.\n\n";
		}
		else
		{
			done = true;
		}
    }
    done = false;
    while (!done)
    {
        cout << "\nWhat is the rating of the restaurant?\nPlease enter a number 0-5: ";
        cin >> rating;
        if (cin.fail() || rating < 0 || rating > 5)
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid response.\n\n";
		}
		else
		{
			done = true;
		}
    }
    done = false;
    while (!done)
    {
        cout << "\nWhat is the phone number of the restaurant?\nPlease enter a 10 digit number ";
        cin >> phoneNumber;
        if (cin.fail() || phoneNumber < 0 || phoneNumber > 9999999999)
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid response.\n\n";
		}
		else
		{
			done = true;
		}
    }
    done = false;
    while (!done)
    {
        //if the restaurant is always open, set openingHour and closingHour to 0000 each
        cout << "Is this restaurant always open? (Y/N) ";
        cin >> alwaysOpen;
        if (alwaysOpen == 'y' || alwaysOpen == 'Y')
		{
		    openingHour = 0;
		    closingHour = 0;
			done = true;
			cin.clear();
			cin.ignore(1000, '\n');
		}
		else if(alwaysOpen == 'n' || alwaysOpen == 'N')
        {
            while (!done)
            {

                cout << "\nWhat is the opening hour of the restaurant?\nPlease enter a number (0000-2400): ";
                cin >> openingHour;
                cin.clear();
                cin.ignore(1000, '\n');
                if (cin.fail() || openingHour < 0 || openingHour > 2400 || openingHour % 100 >= 60)
                {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Invalid response.\n\n";
                }
                else
                {
                    done = true;
                }
            }
            done = false;
            while (!done)
            {
                cout << "\nWhat is the closing hour of the restaurant?\nPlease enter a number (0000-2400): ";
                cin >> closingHour;
                cin.clear();
                cin.ignore(1000, '\n');
                if (cin.fail() || closingHour < 0 || closingHour > 2400 || closingHour % 100 >= 60)
                {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Invalid response.\n\n";
                }
                else
                {
                    done = true;
                }
            }
        }
		else
		{
		    cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid response.\n\n";
		}
    }
    cout << "What is the cuisine of the restaurant? ";
    getline(cin, cuisine);
    cout << "What is the location of the restaurant? ";
    getline(cin, location);

    Restaurant rest;

    //set all the attributes on the local restaurant
    rest.setCost(cost);
    rest.setRating(rating);
    rest.setName(name);
    rest.setClosingHour(closingHour);
    rest.setOpeningHour(openingHour);
    rest.setLocation(location);
    rest.setCuisine(cuisine);
    rest.setPhoneNumber(phoneNumber);

    system(CLEAR);
    cout << rest;
    cout << "\n\nDoes this look right?" << endl << endl;

    //add check for input here later
    cout << "(y/n): ";

    cin.ignore(1000, '\n');

    //we will pass addRestaurant all parameters for a restaurant
    addRestaurant(name, cuisine, location, openingHour, closingHour, rating, cost, phoneNumber);
}












