
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
    int index = hash(rest.getName(), rest.getPhoneNumber());

    if(Table[index]->rest.getName() == "")
        Table[index] = N;
    else
    {
        Nodeptr temp = Table[index];
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = N;
    }
}

int HashTable::hash(string key, double phoneNum)
{
    int index, sum = 0;
    unsigned int phoneN = (int)phoneNum;
    for(int i = 0; i < key.length(); i++)
        sum += (int) key[i]; //summing the ASCII values for each character in the string
    index = (sum+phoneN) % TABLE_SIZE; //dividing the summed ASCII values by 35 && storing remainder as my index
    return index;
}

void HashTable::printTable()
{
    for(int i = 0; i < TABLE_SIZE; i++)
    {
    	cout << "------------------------------------" << endl;
    	cout << "Index " << i << endl;
        cout << Table[i]->rest;
        cout << "Number Values at this Index: " << numItemsAtIndex(i) << endl;
    }
    cout << "------------------------------------" << endl;

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

int HashTable::findRestaurant(string name, double phoneNum)
{
	int index = hash(name, phoneNum);
	Nodeptr temp = Table[index];
	while(temp != NULL)
	{
		if(temp->rest.getName() == name && temp->rest.getPhoneNumber() == phoneNum)
		{
			cout << temp->rest;
			return index;
		}
		temp = temp->next;
	}
	cout << "findRestaurant(): The restaurant is not stored in the database." << endl;
	return -1;
}

void HashTable::removeItem(string name, double phoneNum)
{
    int index = hash(name, phoneNum);
    Nodeptr temp = Table[index];

    if(temp->rest.getName() == "")
    {
    	cout << "1removeItem(): Cannot remove. The book was not found in the table." << endl;
    	return;
   	}
    else if(temp->rest.getName() != "" && !temp->next)
    {
        if(name == temp->rest.getName() && phoneNum == temp->rest.getPhoneNumber())
        {
            delete temp;
            Table[index] = new Node();
        }
        else
		{
			cout << "2removeItem(): Cannot remove. The book was not found in the table." << endl;
			return;
		}
    }
    else
    {
        if(name == temp->rest.getName() && phoneNum == temp->rest.getPhoneNumber())
        {
            Table[index] = temp->next;
            delete temp;
        }
        else
        {
            while(temp->next != NULL)
            {
            	if(temp->next->rest.getName() == name && temp->next->rest.getPhoneNumber() == phoneNum)
            	{
            		Nodeptr temp2 = temp->next;
            		temp->next = temp2->next;
            		delete temp2;
            		return;
            	}
            	temp = temp->next;
            }
            cout << "3removeItem(): Cannot remove. The book was not found in the table." << endl;
        }
    }
}

int HashTable::getTableSize()
{
    return TABLE_SIZE;
}

int HashTable::numItemsAtIndex(int index)
{
	Nodeptr temp = Table[index];
	int count = 0;
	if(temp->rest.getName() == "")
		return count;
	while(temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return count;
}

void HashTable::printBucket(int index)
{
	Nodeptr temp = Table[index];
	cout << "Values Stored at Bucket " << index << ":" << endl << endl;
	while(temp != NULL)
	{
		cout << temp->rest << endl;
		temp = temp->next;
	}
}

