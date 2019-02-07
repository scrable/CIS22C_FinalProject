#include "MainMenu.h"

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif // _WIN32

MainMenu::MainMenu()
{
    //create a pointer to the unique key BST
    uniqueBSTDatabase = new BST<string>();

    //create a pointer to the secondary key
    secondaryBSTDatabase = new BST<string>();

    //create a pointer to the hash table
    hashTable = new HashTable();

    //create a pointer to the restaurantDatabase object to call the database functions
    restaurantDatabase = new RestaurantDatabase(uniqueBSTDatabase, secondaryBSTDatabase, hashTable);

    //this report call to the constructor will create a report object to be used by the main menu object
    //report will be used for search, list, and statistics
    report = Report(uniqueBSTDatabase, secondaryBSTDatabase, hashTable);
}

MainMenu::~MainMenu()
{
    restaurantDatabase->writeFile();
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
        cout << "\t    2. Remove a restaurant from the database\n";
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
            restaurantDatabase->removeRestaurantMenu();
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
            system(CLEAR);
            fileSaveMenu();
        }
        else if (choice == 7)
        {
            system(CLEAR);
            cout << "\n\n\t\tThank you for using the restaurant database!\n\n";
            cout << "\t\t\tPress return to exit.";
            cin.ignore();
            cin.get();
            system(CLEAR);
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
    }
    while (choice != 7);
}

void MainMenu::fileLoadMenu()
{
    // asks the user if they want to use a specific database file, then sets the database file to what they chose
    bool databaseFileDone = false;
    string response;
    while (!databaseFileDone)
    {
        cout << "Do you want to specify where the database will be loaded from? (Y/N) ";
        cin >> response;
        if (response == "y" || response == "Y")
        {
            cout << "\nWhere do you want to load the database from? ";
            cin >> response;
            restaurantDatabase->setInputDatabaseFile(response);

            cout << "\nThe database will be loaded from " << response << endl << endl;
            databaseFileDone = true;
        }
        else if (response == "n" || response == "N")
        {
            cout << "\nDefault location will be used. (./input.txt)\n";
            databaseFileDone = true;
        }
        else
        {
            cout << "That is not a valid response.\n";
        }
    }

    // if the database file already exists, read from existing file
    ifstream ifile(restaurantDatabase->getInputDatabaseFile().c_str());
    if (ifile)
    {
        restaurantDatabase->readFile();
        cout << "Existing database was read from " << restaurantDatabase->getInputDatabaseFile() << "." << endl;
    }
    cout << "\n\n\t\tPress return to continue.";
    cin.ignore(1000, '\n');
    cin.clear();
    cin.get();
    ifile.close();
}

void MainMenu::fileSaveMenu()
{
    // asks the user if they want to use a specific database file, then sets the database file to what they chose
    bool databaseFileDone = false;
    string response;
    while (!databaseFileDone)
    {
        cout << "Do you want to specify where the database will be saved? (Y/N) ";
        cin >> response;
        if (response == "y" || response == "Y")
        {
            cout << "\nWhere do you want to save the database to? ";
            cin >> response;
            restaurantDatabase->setOutputDatabaseFile(response);

            cout << "\nThe database will be saved to " << response << endl << endl;
            databaseFileDone = true;
        }
        else if (response == "n" || response == "N")
        {
            cout << "\nDefault location will be used. (./output.txt)\n";
            databaseFileDone = true;
        }
        else
        {
            cout << "That is not a valid response.\n";
        }
    }

    restaurantDatabase->writeFile();
    cout << "\n\n\t   The restaurant database has been written to " << restaurantDatabase->getOutputDatabaseFile() << "." << endl;
    cout << "\n\n\t\tPress return to continue.";
    cin.ignore(1000, '\n');
    cin.clear();
    cin.get();
}

//this is where our main will be
int main()
{
    //we will want to create a MainMenu object here to run the main menu
    MainMenu menu;
    menu.fileLoadMenu();
    menu.showMainMenu();
}
