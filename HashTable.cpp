
#include "HashTable.h"
#include <iomanip>

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
    if
    (
       Table[index]->rest.getName() == rest.getName()
       && Table[index]->rest.getCuisine() == rest.getCuisine()
       && Table[index]->rest.getLocation() == rest.getLocation()
       && Table[index]->rest.getOpeningHour() == rest.getOpeningHour()
       && Table[index]->rest.getClosingHour() == rest.getClosingHour()
       && Table[index]->rest.getPhoneNumber() == rest.getPhoneNumber()
       && Table[index]->rest.getRating() == rest.getRating()
       && Table[index]->rest.getCost() == rest.getCost()
    )
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
    index = sum % TABLE_SIZE; //dividing the summed ASCII values by 35 && storing remainder as my index
    return index;
}

//int HashTable::numItemsAtIndex(int index)
//{
//    Nodeptr temp = Table[index];
//    int count = 0;
//    if(temp->title == "")
//        return count;
//    else
//        while(temp)
//        {
//            count++;
//            temp = temp->next;
//        }
//    return count;
//}

void HashTable::printTable()
{
    for(int i = 0; i < TABLE_SIZE; i++)
    {
        if(Table[i]->rest.getName() != "default name")
        {
            cout << "BUCKET NUMBER: " << i;
            cout << "\n------------------------------------" << endl << endl;
            cout << Table[i]->rest << endl;
            if(Table[i]->next)
            {
                Nodeptr temp = Table[i];
                while(temp->next)
                {
                    cout << temp->next->rest << endl;
                    temp = temp->next;
                }
            }
        }
    }
    cout << "\n------------------------------------" << endl << endl;
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
    //Restaurant r;
    return index;
}

void HashTable::printBucket(int index)
{
    Nodeptr temp = Table[index];
    if(temp)
    {
        int i = 1;
        while(temp)
        {
            cout << i << endl << temp->rest;
            temp = temp->next;
            i++;
        }
    }
    else
        cout << "The bucket at index "<< index << " is empty." << endl;
}

Restaurant HashTable::getRestaurant(int num, int index)
{
    Nodeptr temp = Table[index];
    for(int i = 1; i < num; i ++)
    {
        temp = temp->next;
    }
    return temp->rest;
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

