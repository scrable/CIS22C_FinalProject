#include "Report.h"
#include <cstdlib>
#include <iostream>

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif // _WIN32

using namespace std;

Report::Report()
{

}

Report::Report(BST<string>* database)
{
    uniqueBSTDatabase = database;
}

    /* SEARCH */

void Report::searchMainMenu()
{
    int choice;

    do
	{
        system(CLEAR);

		//show the mainMenu and get the choice
		cout << "\t\tSearch\n\t\tMain Menu\n\n";
		cout << "\t    1. Search restaurants by name\n";
		cout << "\t    2. Search restaurants by cuisine\n";
		cout << "\t    3. Return to main menu\n";
		cout << "\n\t     Enter your choice: ";

		cin >> choice;

		if (choice == 1)
		{
			//run searchByName();
			searchByName();
		}
		else if (choice == 2)
		{
			//run searchByCuisine();
			searchByCuisine();
		}
		else if (choice == 3)
		{
			//return to main menu
			break;
		}
		else
		{
			system(CLEAR);
			cout << "\n\t    Please enter a valid selection.\n";
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "\n\t    Press return to continue.";
			cin.get();
			choice = 0;
		}
	} while (choice != 3);
}

void Report::searchByName()
{
    //temp variable to hold the value to search for
    //case sensitive
    string tempRestaurantName;

    system(CLEAR);
    cout << "Enter the name of the restaurant to search for: ";
    cin >> tempRestaurantName;
}

void Report::searchByCuisine()
{

}

    /* LIST */

void Report::listMainMenu()
{
    int choice;

    do
	{
	    system(CLEAR);


		//show the mainMenu and get the choice
		cout << "\t\tList\n\t\tMain Menu\n\n";
		cout << "\t    1. List unsorted data\n";
		cout << "\t    2. List data sorted by name\n";
		cout << "\t    3. List data sorted by cuisine\n";
		cout << "\t    4. Return to main menu\n";
		cout << "\n\t     Enter your choice: ";

		cin >> choice;

		if (choice == 1)
		{
			//run listUnsorted();
		}
		else if (choice == 2)
		{
			//run listSortedByName();
		}
		else if (choice == 3)
		{
			//run listSortedByCuisine();
		}
		else if (choice == 4)
		{
			//return to main menu
			break;
		}
		else
		{
			#ifdef WINDOWS
            system("CLS");//clear the screen of any old menus
            #else
                system("clear");
            #endif
			cout << "\n\t    Please enter a valid selection.\n";
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "\n\t    Press return to continue.";
			cin.get();
			choice = 0;
		}
	} while (choice != 4);
}

void Report::listUnsorted()
{
    return;
}

void Report::listSortedByName()
{
    return;
}

void Report::listSortedByCuisine()
{
    return;
}


/* STATISTICS */

void Report::statisticsMainMenu()
{
    int choice;

    do
	{
	    system(CLEAR);


		//show the mainMenu and get the choice
		cout << "\t\tStatistics\n\t\tMain Menu\n\n";
		cout << "\t    1. List unsorted data\n";
		cout << "\t    2. List data sorted by name\n";
		cout << "\t    3. List data sorted by cuisine\n";
		cout << "\t    4. Return to main menu\n";
		cout << "\n\t     Enter your choice: ";

		cin >> choice;

		if (choice == 1)
		{
			//run restaurantsPerCuisine;
		}
		else if (choice == 2)
		{
			//run restaurantsBestRating;
		}
		else if (choice == 3)
		{
			//run affordableRestaurants();
		}
		else if (choice == 4)
		{
			//return to main menu
			break;
		}
		else
		{
			system(CLEAR);
			cout << "\n\t    Please enter a valid selection.\n";
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "\n\t    Press return to continue.";
			cin.get();
			choice = 0;
		}
	} while (choice != 4);
}

void Report::restaurantsPerCuisine()
{

}

void Report::restaurantsBestRating()
{

}
void Report::affordableRestaurants()
{

}


