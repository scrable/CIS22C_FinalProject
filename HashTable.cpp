#include "HashTable.h"

HashTable::HashTable()
{
    for(int i = 0; i <TABLE_SIZE; i++)
    {
        Table[i] = new Node();
    }
}

HashTable::~HashTable()
{
    for(int i = 0; i <TABLE_SIZE; i++)
    {
        Nodeptr temp = Table[i]->next;
        Nodeptr tempHelper;
        delete Table[i];
        while(temp)
        {
            tempHelper = temp;
            temp = temp->next;
            delete tempHelper;
        }
    }
}

void HashTable::addItem(Restaurant rest)
{
    Nodeptr N = new Node(rest);
    int index = hash(rest.getName());

    //check for duplicate restaurant
    //dont add the restaurant if all parameters are equal
    if(Table[index]->rest == rest)
    {
        return;
    }
    if(Table[index]->rest.getName() == "default name")
        Table[index] = N;
    else
    {
        Nodeptr temp = Table[index];
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = N;
    }
}

int HashTable::hash(string key)
{
    int index, sum = 0, keyLength = 0;
    keyLength = key.length();
    for(int i = 0; i < keyLength; i++)
        sum += (int) key[i]; //summing the ASCII values for each character in the string
    index = sum % TABLE_SIZE; //dividing the summed ASCII values by 60 && storing remainder as my index
    return index;
}

void HashTable::printTableToFile(ofstream &fout)
{
    for(int i = 0; i < TABLE_SIZE; i++)
    {
        if(Table[i]->rest.getName() != "default name")
        {
            //cant use operator overload here because the overload
            //prints extra chars
            //ex Name: and Cuisine:
            fout << fixed << setprecision(0);
            fout << Table[i]->rest.getName() << endl;
            fout << Table[i]->rest.getCuisine() << endl;
            fout << Table[i]->rest.getLocation() << endl;
            fout << Table[i]->rest.getOpeningHour() << endl;
            fout << Table[i]->rest.getClosingHour() << endl;
            fout << Table[i]->rest.getCost() << endl;
            fout << fixed << setprecision(1);
            fout << Table[i]->rest.getRating() << endl;
            fout << fixed << setprecision(0);
            fout << Table[i]->rest.getPhoneNumber() << endl;
            if(Table[i]->next)
            {
                Nodeptr temp = Table[i];
                while(temp->next)
                {
                    temp = temp->next;
                    fout << fixed << setprecision(0);
                    fout << temp->rest.getName() << endl;
                    fout << temp->rest.getCuisine() << endl;
                    fout << temp->rest.getLocation() << endl;
                    fout << temp->rest.getOpeningHour() << endl;
                    fout << temp->rest.getClosingHour() << endl;
                    fout << temp->rest.getCost() << endl;
                    fout << fixed << setprecision(1);
                    fout << temp->rest.getRating() << endl;
                    fout << fixed << setprecision(0);
                    fout << temp->rest.getPhoneNumber() << endl;
                }
            }
        }
    }
}

int HashTable::findRestaurant(string key)
{
    int index = hash(key);
    Nodeptr temp = Table[index];
    while(temp)
    {
        if(temp->rest.getName() == key)
        {
            cout << temp->rest;
            return index;
        }
        else
            temp = temp->next;
    }
    cout << "\n\tThe restaurant " << key << " is not in the database.";
    return -1;
}

Restaurant HashTable::getRestaurant(int num, int index, string tempName)
{
    Nodeptr temp = Table[index];

    int i = 1;

    //if restaurant doesn't exist
    if((!temp->next && temp->rest.getName() != tempName) || num > numItemsAtIndex(index))
    {
        Restaurant r;
        return r;
    }

    //if the restaurant we want is the first item in the hashs index
    if(temp->rest.getName() == tempName && num == 1)
        return temp->rest;

    while(temp->next)
    {
        i++;
        temp = temp->next;
        if(i == num)
            break;
    }
    if(i == num)
        //return the currect restaurant
        return temp->rest;
    else
    {
        Restaurant r;
        return r;
    }
}

void HashTable::removeItem(Restaurant r)
{
    int index = hash(r.getName());
    Nodeptr temp = Table[index];


    if(!temp)
    {
        cout << "Cannot remove the item. The bucket is empty.";
    }
    else if(temp && !temp->next)
    {
        if(r == temp->rest)
        {
            delete temp;
            Table[index] = new Node();
        }
        else
            cout << "Could not find " << r << endl;

    }
    else if(temp && temp->next)
    {
        if(r == temp->rest)
        {
            Table[index] = temp->next;
            delete temp;
        }
        else
        {
            while(!(temp->next->rest == r) && temp->next)
            {
                temp = temp->next;
            }
            if(temp->next->rest == r)
            {
                if(temp->next->next)
                {
                    delete temp->next;
                    temp->next = temp->next->next;
                }
                else
                {
                    delete temp->next;
                    temp->next = NULL;
                }
            }
            else
                cout << "Could not find " << r;
        }
    }
}

int HashTable::getTableSize()
{
    return TABLE_SIZE;
}

bool HashTable::affordableRestaurant(int cost)
{
    bool found = false;
    cout << endl;

    for(int i = 0; i < TABLE_SIZE; i++)
    {
        Nodeptr temp= Table[i];
        while (temp != NULL)
        {
            if (temp->rest.getCost() <= cost && temp->rest.getName() != "default name")
            {
                found = true;
                cout << "------------------------------------" << endl;
                cout << temp->rest;
            }
            temp = temp->next;
        }
    }
    return found;
}

int HashTable::printRest(int index, string tempName)
{
    Nodeptr temp = Table[index];
    int count = 0;

    if(temp)
    {
        while(temp)
        {
            if(tempName == temp->rest.getName())
            {
                count++;
                cout << "Restaurant number: " << count << endl << temp->rest << endl;
            }
            temp = temp->next;
        }
    }
    return count;
}

int HashTable::numItemsAtIndex(int index)
{
    Nodeptr temp = Table[index];
    int count = 0;
    if(temp->rest.getName() == "default name")
        return count;
    else
        while(temp)
        {
            count++;
            temp = temp->next;
        }
    return count;
}

bool HashTable::findRestaurantRating(double rating)
{
    bool found = false;
    cout << endl;

    for(int i = 0; i < TABLE_SIZE; i++)
    {
        Nodeptr temp= Table[i];
        while (temp != NULL)
        {
            if (temp->rest.getRating() >= rating && temp->rest.getRating() != -1)
            {
                found = true;
                cout << "------------------------------------" << endl;
                cout << temp->rest;
            }
            temp = temp->next;
        }
    }
    return found;
}
