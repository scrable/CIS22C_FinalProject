#include "RestaurantDatabase.h"

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif // _WIN32

RestaurantDatabase::RestaurantDatabase()
{

}

RestaurantDatabase::RestaurantDatabase(BST<string>* uniqueBST, BST<string>* secondaryBST, HashTable* table)
{
    uniqueBSTDatabase = uniqueBST;
    secondaryBSTDatabase = secondaryBST;
    hashTable = table;
    inputDatabaseFile = "input.txt";
    outputDatabaseFile = "output.txt";
}

void RestaurantDatabase::setInputDatabaseFile(string file)
{
    inputDatabaseFile = file;
}

string RestaurantDatabase::getInputDatabaseFile()
{
    return inputDatabaseFile;
}

void RestaurantDatabase::setOutputDatabaseFile(string file)
{
    outputDatabaseFile = file;
}

string RestaurantDatabase::getOutputDatabaseFile()
{
    return outputDatabaseFile;
}

//run this when we need to write to a file
//this will output ALL of the data structures to a file
//this is supposed to be run automatically when the program ends, so we will add it to our destructor
void RestaurantDatabase::writeFile()
{
    //output the restaurants to a file
    //output all of the data for each restaurant
    try
    {
        ofstream fout;
        fout.open(getOutputDatabaseFile().c_str());

        if(fout.fail())
        {
            "Failed to open " + outputDatabaseFile + " for writing.\n";
        }
        hashTable->printTableToFile(fout);
        fout.close();
    }
    catch(string e)
    {
        cout << e;
    }
    return;
}

void RestaurantDatabase::readFile()
{
    try
    {
        ifstream fin;
        fin.open(inputDatabaseFile.c_str());
        // if unable to open database file, throw error
        if (fin.fail())
        {
            throw "Failed to open " + inputDatabaseFile + " for reading.\n";
        }

        //read the file in a for loop, inputting a complete restaurant object
        //to all 3 databases by calling addRestaurant
        int i = 0;
        while(!fin.eof())
        {
            //declare a temp object to add
            Restaurant rest;

            //read in all contents
            fin >> rest;

            //add the restaurant if it is not a default object
            //must check if name is an empty line here
            //otherwise it will add an invalid restaurant
            if(rest.getName() != "default name" && rest.getName() != "")
                addRestaurant(rest);

            //increment iterator
            i++;
        }
        //close the input file
        fin.close();
    }
    //if database file is unreadable
    catch (string e)
    {
        cout << e;
    }
}

void RestaurantDatabase::addRestaurant(Restaurant rest)
{
    //add the new restaurant to all 3 databases
    uniqueBSTDatabase->insertName(rest);
    secondaryBSTDatabase->insertCuisine(rest);
    hashTable->addItem(rest);
}

void RestaurantDatabase::removeRestaurantMenu()
{
    system(CLEAR);

    string tempName;
    int num;
    bool done = false;

    cin.clear();
    cin.ignore(1000, '\n');
    uniqueBSTDatabase->inOrderPrint();
    cout << "What is the name of the restaurant you would like to delete? ";
    getline(cin, tempName);
    if(uniqueBSTDatabase->searchName(tempName))
    {
        //check valid input against numitemsinbucket
        while(!done)
        {
            system(CLEAR);

            cout << endl;
            int index = hashTable->hash(tempName);
            hashTable->printRest(index, tempName);

            cout << "Enter the number of the restaurant you wish to remove\nor enter -1 to return to main menu: ";
            if(cin >> num)
            {
                if(num > 0)
                {
                    //get the restaurant that the user specifies
                    Restaurant r = hashTable->getRestaurant(num, index, tempName);
                    if(r.getName() != "default name")
                    {
                        system(CLEAR);
                        cout << "\n\t\tRestaurant removed.";
                        removeRestaurant(r);
                        cin.ignore(1000, '\n');
                        cout << "\n\t\tPress return to continue." << endl;
                        cin.get();
                        done = true;
                    }
                    else
                    {
                        cout << "\n\tPlease enter a valid restaurant number.";
                        cout << "\n\n\n\t\tPress return to continue." << endl;
                        cin.ignore(1000, '\n');
                        cin.get();
                    }
                }
                else if(num == -1)
                {
                    done = true;
                }
                else
                {
                    cout << "\n\tPlease enter a valid restaurant number";
                    cout << "\n\n\n\t\tPress return to continue." << endl;
                    cin.ignore(1000, '\n');
                    cin.get();
                }
            }
            else
            {
                cout << "\n\tPlease enter a valid restaurant number";
                cout << "\n\n\n\t\tPress return to continue." << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                cin.get();
            }
        }
    }
    else
    {
        cout << "The restaurant with the name " << tempName << " does not exist in the database." << endl;
        cout << "\n\n\n\t\tPress return to continue." << endl;
        cin.get();
    }

}

void RestaurantDatabase::removeRestaurant(Restaurant r)
{
    hashTable->removeItem(r);
    uniqueBSTDatabase->removeName(r);
    secondaryBSTDatabase->removeCuisine(r);
}

void RestaurantDatabase::addRestaurantMenu()
{
    bool done = false;
    bool restAdded = false;
    string name;
    string cuisine;
    string location;
    int openingHour;
    int closingHour;
    int cost;
    double phoneNumber;
    double rating;
    string alwaysOpen;


    system(CLEAR);

    while (!restAdded)
    {
        //get info for the restaurant
        cin.clear();
        cin.ignore(1000, '\n');
        done = false;
        while (!done)
        {
            cout << "What is the name of the restaurant? ";
            getline(cin, name);
            if(name == "")
            {
                cin.clear();
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
            cout << "\nWhat is the cost consideration of the restaurant?\nPlease enter a number 1-4: ";
            cin >> cost;
            if (cin.fail() || cost < 1 || cost > 4)
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
            cout << "\nWhat is the rating of the restaurant?\nPlease enter a number 0.0-5.0: ";
            cin >> rating;
            if (cin.fail() || rating < 0 || rating > 5 || fmod(rating, .5) != 0)
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
            cout << "\nWhat is the phone number of the restaurant?\nPlease enter a 10 digit number: ";
            cin >> phoneNumber;
            if (cin.fail() || phoneNumber <= 0 || phoneNumber > 9999999999 || phoneNumber < 1000000000 )
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
            cout << "\nIs this restaurant always open? (Y/N) ";
            cin >> alwaysOpen;
            if (alwaysOpen == "Y" || alwaysOpen == "y")
            {
                openingHour = 0;
                closingHour = 0;
                done = true;
                cin.clear();
                cin.ignore(1000, '\n');
            }
            else if(alwaysOpen == "n" || alwaysOpen == "N")
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
        cout << "\nWhat is the cuisine of the restaurant? ";
        getline(cin, cuisine);
        cout << "\nWhat is the location of the restaurant? ";
        getline(cin, location);

        Restaurant rest;

        //set all the attributes on the local restaurant
        rest.setAll(name, cuisine, location, openingHour, closingHour, cost, rating, phoneNumber);

        system(CLEAR);



        done = false;
        string response;
        while (!done)
        {

            cout << rest;
            cout << "\n\nDoes this look right?" << endl << endl;
            cout << "(Y/N): ";
            cin >> response;
            if (response == "y" || response == "Y")
            {
                system(CLEAR);
                //we will pass addRestaurant all parameters for a restaurant
                addRestaurant(rest);
                cout << "\n\n\n\t\tRestaurant added successfully!\n\t\tPress return to continue." << endl;
                cin.ignore(1000, '\n');
                cin.get();
                system(CLEAR);

                while (!done)
                {
                    cout << "Would you like to enter another restaurant? ";
                    cout << "(y/n): ";
                    cin >> response;
                    if (response == "y" || response == "Y")
                    {
                        system(CLEAR);
                        restAdded = false;
                        done = true;
                    }
                    else if (response == "n" || response == "N")
                    {
                        system(CLEAR);
                        restAdded = true;
                        done = true;
                        return;
                    }
                    else
                    {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "Invalid response.\n\n";
                    }
                }
            }
            else if (response == "n" || response == "N")
            {
                system(CLEAR);
                cout << "Would you like to try adding the restaurant again? ";
                cout << "(Y/N): ";
                cin >> response;
                while (!done)
                {
                    if (response == "y" || response == "Y")
                    {
                        system(CLEAR);
                        restAdded = false;
                        done = true;
                    }
                    else if (response == "n" || response == "N")
                    {
                        system(CLEAR);
                        restAdded = true;
                        done = true;
                        return;
                    }
                    else
                    {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "Invalid response.\n\n";
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
    }
}
