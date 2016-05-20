#include "MainMenu.h"
#include "RestaurantDatabase.h"
#include "BST.h"
#include <cstdlib>
#include <iostream>

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif // _WIN32

using namespace std;

MainMenu::MainMenu()
{


    //create a pointer to the unique key BST
    uniqueBSTDatabase = new BST<string>();

    //create a pointer to the secondary key
    secondaryBSTDatabase = new BST<string>();

     //create a pointer to the hash table
     //when adding the hash here, make sure to add it to the restaurantDatabase assignment below
     //as well as the constructor for the RestaurantDatabase

    //create a restaurantDatabase object to call the database functions
    restaurantDatabase = new RestaurantDatabase(uniqueBSTDatabase, secondaryBSTDatabase);

    //will need to pass in database as an argument to Report() once it is added
    //will also need a new constructor for this to happen
    //this report call to the constructor will create a report object to be used by the main menu object
    //report will be used for search, list, and statistics
    report = Report(uniqueBSTDatabase, secondaryBSTDatabase);






}

MainMenu::~MainMenu()
{

}

void MainMenu::showMainMenu()
{
	int choice = 0;
	do
	{
	    system(CLEAR);

		//show the mainMenu and get the choice
		cout << "\t\tRestaurants\n\t\tMain Menu\n\n";
		cout << "\t    1. Add a restaurant to the database\n";
		cout << "\t    2. Delete a restaurant from the database\n";
		cout << "\t    3. Search for a restaurant\n";
		cout << "\t    4. List all restaurants\n";
		cout << "\t    5. Statistics about the restaurants\n";
		cout << "\t    6. Write restaurant database to a file\n";
		cout << "\t    7. Exit\n";
		cout << "\n\t     Enter your choice: ";

		cin >> choice;

		if (choice == 1)
		{
			//run add new data menu
			restaurantDatabase->addRestaurantMenu();
		}
		else if (choice == 2)
		{
			//run removeRestaurant();
			restaurantDatabase->removeRestaurant();
		}
		else if (choice == 3)
		{
			//run search main menu
			report.searchMainMenu();
		}
		else if (choice == 4)
		{
			//run list main menu
			report.listMainMenu();
		}
		else if (choice == 5)
		{
			//run statistics main menu;
			report.statisticsMainMenu();

		}
		else if (choice == 6)
		{
			//run writeFile();
		}
		else if (choice == 7)
		{
			system(CLEAR);
			cout << "\n\n\t\t   Thank you for using the restaurant database!\n\n";
			cout << "\t\t\t(Press return to continue)";
			cin.ignore();
			cin.get();
			return;
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
	} while (choice != 7);
}

//this is where our main will be
int main()
{
    //we will want to create a MainMenu object here to run the main menu
    MainMenu menu;
    menu.showMainMenu();
}
