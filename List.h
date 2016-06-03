#ifndef LIST_H_
#define LIST_H_

template <class listitem>
class List
{

private:
    struct Node
    {
        Node* next;
        Node* previous;
        listitem data;

        Node(): next(NULL), previous(NULL) {} //define our own default constructor
        Node(listitem data): next(NULL), previous(NULL), data(data) {}
    };

    typedef struct Node* Nodeptr;

    unsigned int length;
    Nodeptr head;
    Nodeptr tail;
    Nodeptr cursor; //the iterator

    void reverse(Nodeptr node);
    //Helper function for the public printReverse() function.
    //Recursively prints the data in a List in reverse.


public:

    /**Constructors and Destructors*/

    List();
    //Default constructor; initializes and empty list
    //Postcondition: all values must be initialized

    ~List();
    //Destructor. Frees memory allocated to the list
    //Postcondition: memory previously allocated is free

    listitem get_cursor();
    //Returns the element pointed to by the iterator
    //Precondition: list must not be empty

    bool off_end();
    //Determines if the iterator is off the end of the list (i.e. whether cursor is NULL)


    int get_length();
    //Returns the length of the list

    int linear_search(listitem value);
    //Searchs the list, element by element, from the head of the List to the tail of the List
    //Returns the index of the value, if it is found in the List
    //Returns -1 if the element is not in the List
    //Does not need to be implemented recursively
    //Pre: !empty()

    /**Manipulation Procedures*/

    bool start_cursor();
    //Moves the iterator to point to the first element in the list
    //If the list is empty, the iterator remains NULL
    //Postcondition: cursor either points to NULL or the first element

    void insert_tail(listitem data);
    //Inserts a new element at the end of the list
    //If the list is empty, the new element becomes both head and tail
    //Postcondition: the nes element added is last in the list

    void insert_head(listitem data);
    //Inserts a new element at the front of the list
    //If the list is empty, the new element becomes both head and tail
    //Postcondition: List contains one new element at the head


    void delete_cursor();
    //Removes the element after the element pointed at by the iterator
    //Precondition: list must not be empty
    //Postcondition: list contains one fewer item

    void move_cursor();
    //Moves the iterator forward by one element in the list
    //Has no effect if the iterator is offend or the list is empty
    //Postcondition: cursor moves to the next element

    void print();
    //Prints to the console the value of each element in the list sequentially
    //and separated by a blank space
    //Prints nothing if the list is empty
};

//constructor
template <class listitem>
List<listitem>::List(): length(0), head(NULL), tail(NULL), cursor(NULL) {}

//destructor
template <class listitem>
List<listitem>::~List()
{
    cursor = head;
    Nodeptr temp;
    while(cursor != NULL)
    {
        temp = cursor->next;
        delete cursor;
        cursor = temp;
    }
}

template <class listitem>
void List<listitem>::insert_head(listitem data)
{
    if (length!=0)
    {
        Nodeptr N = new Node(data);//create the new node by calling the node constructor
        N->next = head;//set the new node's next field to point to the head
        head->previous = N;//point the old head nodes previous to the new node
        head = N;//make the head be the new node
    }
    else
    {
        head = new Node(data);
        tail = head;
    }
    length++;
}

template <class listitem>
void List<listitem>::insert_tail(listitem data)
{
    if (length!=0)
    {
        Nodeptr N = new Node(data);//create the new node by calling the node constructor
        N->previous = tail;//point the new nodes previous to the old tail
        tail->next = N;//set the old tails next field to point to the new node
        tail = N;//make the new node the tail
    }
    else
    {
        head = new Node(data);
        tail = head;
    }
    length++;
}

template <class listitem>
void List<listitem>::print()
{
    Nodeptr temp = head; //create a temporary iterator
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

template <class listitem>
int List<listitem>::get_length()
{
    return length;
}

template <class listitem>
bool List<listitem>::start_cursor()
{
    if(length == 0)
    {
        cout << "\n\n\tThere are no restaurants in the database." << endl;
        return false;
    }
    else
    {
        cursor = head;
        return true;
    }
}

template <class listitem>
listitem List<listitem>::get_cursor()
{
    return cursor->data;
}

template <class listitem>
void List<listitem>::move_cursor()
{
    if(length == 0)
    {
        cout << "move_cursor(): The list is empty.\n";
    }
    else if(off_end())
    {
        cout << "move_cursor(): Cursor is offend.\n";
    }
    else cursor = cursor->next;
}

template <class listitem>
bool List<listitem>::off_end()
{
    return (cursor == NULL);
}

template <class listitem>
int List<listitem>::linear_search(listitem value)
//Searchs the list, element by element, from the head of the List to the tail of the List
//Returns the index of the value, if it is found in the List
//Returns -1 if the element is not in the List
//Does not need to be implemented recursively
//Pre: !empty()
{
    if(length == 0)
    {
        cout << "linear_search(): The list is empty.";
        return -1;
    }
    else
    {
        Nodeptr tempCursor = cursor;
        cursor = head;
        for(unsigned int i = 1; i <= length; i++)
        {
            if (cursor->data == value)
            {
                cursor = tempCursor;
                return i;
            }
            cursor = cursor->next;
        }
        cursor = tempCursor;
        return -1;
    }
}

#endif // LIST_H_
