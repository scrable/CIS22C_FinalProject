#include "Report.h"

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif // _WIN32

Report::Report()
{

}

Report::Report(BST<string>* uniqueBST, BST<string>* secondaryBST, HashTable* table)
{
    uniqueBSTDatabase = uniqueBST;
    secondaryBSTDatabase = secondaryBST;
    hashTable = table;
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
            cout << "\n\t    Press any key to continue.";
            cin.get();
            choice = 0;
        }
    }
    while (choice != 3);
}

void Report::searchByName()
{
    string tempRestaurantName;

    system(CLEAR);
    cin.clear();
    cin.ignore(1000, '\n');

    cout << "Enter the name of the restaurant to search for: ";
    getline(cin, tempRestaurantName);

    hashTable->findRestaurant(tempRestaurantName);

    cout << "\n\n\t\tPress any key to continue." << endl;
    cin.get();
}

void Report::searchByCuisine()
{
    string tempCuisine;

    system(CLEAR);
    cin.clear();
    cin.ignore(1000, '\n');

    cout << "Enter the cuisine you would like to search for: ";
    getline(cin, tempCuisine);

    secondaryBSTDatabase->searchCuisine(tempCuisine);

    cout << "Press any key to continue.";
    cin.get();

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
            listUnsorted();
        }
        else if (choice == 2)
        {
            //run listSortedByName();
            listSortedByName();
        }
        else if (choice == 3)
        {
            //run listSortedByCuisine();
            listSortedByCuisine();
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
            cout << "\n\t    Press any key to continue.";
            cin.get();
            choice = 0;
        }
    }
    while (choice != 4);
}

void Report::listUnsorted()
{
    system(CLEAR);
    cout << "Listing unsorted restaurant database: " << endl;

    //will change this back later to use preOrderPrint to display unsorted info
    //uniqueBSTDatabase->preOrderPrint();
    hashTable->printTable();

    cin.clear();
    cin.ignore(1000, '\n');
    cout << "\n\t    Press any key to continue.";
    cin.get();
    return;
}

void Report::listSortedByName()
{
    system(CLEAR);
    cout << "Listing restaurants in the database sorted by name: " << endl;
    uniqueBSTDatabase->inOrderPrint();
    cout << "\n------------------------------------" << endl << endl;
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "\n\t    Press any key to continue.";
    cin.get();
    return;
}

void Report::listSortedByCuisine()
{
    system(CLEAR);
    cout << "Listing restaurants in the database sorted by cuisine: " << endl;
    secondaryBSTDatabase->inOrderPrint();
    cout << "\n------------------------------------" << endl << endl;
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "\n\t    Press any key to continue.";
    cin.get();
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
        cout << "\t    1. Show number of restaurants per cuisine\n";
        cout << "\t    2. Show restaurants with acceptable rating\n";
        cout << "\t    3. Show affordable restaurants\n";
        cout << "\t    4. Return to main menu\n";
        cout << "\n\t     Enter your choice: ";

        cin >> choice;

        if (choice == 1)
        {
            //run restaurantsPerCuisine();
            restaurantsPerCuisine();
        }
        else if (choice == 2)
        {
            //run restaurantsBestRating();
            restaurantsBestRating();
        }
        else if (choice == 3)
        {
            //run affordableRestaurants();
            affordableRestaurants();
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
            cout << "\n\t    Press any key to continue.";
            cin.get();
            choice = 0;
        }
    }
    while (choice != 4);
}

void Report::restaurantsPerCuisine()
{
    system(CLEAR);
    secondaryBSTDatabase->buildCuisineList();
    cin.ignore(1000, '\n');
    cout << "\n\t    Press any key to continue.";
    cin.get();
}

void Report::restaurantsBestRating()
{
    double rating = 0;
    bool done = false;
    while(!done)
    {
        system(CLEAR);
        cout << "What rating are you willing to accept? (0.5-5.0): ";
        if(cin >> rating)
        {
            if(fmod(rating, .5) != 0 || rating < 0 || rating > 5)
            {
                system(CLEAR);
                cout << "\n\t\tInvalid rating." << endl;
                cin.ignore(1000, '\n');
                cout << "\n\t    Press any key to continue.";
                cin.get();
            }
            else done = true;
        }
        else
        {
            system(CLEAR);
            cout << "\n\t    Invalid rating.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\n\t    Press any key to continue.";
            cin.get();
        }
    }

    if(!hashTable->findRestaurantRating(rating))
        cout << "\n\n\tNo restaurants with a rating of " << rating << " or lower could be found.\n";
    cin.ignore(1000, '\n');
    cout << "\n\t    Press any key to continue.";
    cin.get();
}

void Report::affordableRestaurants()
{
    int cost = 0;
    bool done = false;
    while(!done)
    {
        system(CLEAR);
        cout << "What is the cost you are willing to pay? (1-4): ";
        if (cin >> cost)
        {
            if(cost < 1 || cost > 4)
            {
                system(CLEAR);
                cout << "\n\t    Invalid cost.\n";
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "\n\t    Press any key to continue.";
                cin.get();
            }
            else done = true;
        }
        else
        {
            system(CLEAR);
            cout << "\n\t    Invalid cost.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\n\t    Press any key to continue.";
            cin.get();
        }
    }

    if(!hashTable->affordableRestaurant(cost))
        cout << "\n\n\tNo restaurants with " << cost << " or lower cost could be found.\n";
    cin.ignore(1000, '\n');
    cout << "\n\t    Press any key to continue.";
    cin.get();
}

