#ifndef _BST_H_
#define _BST_H_

#include <iostream>
#include "Restaurant.h"
#include "List.h"

template <class bstdata>
class BST
{
private:
    struct Node
    {
        Node* left;
        Node* right;
        Restaurant rest;

        Node(): left(NULL), right(NULL), rest() {}
        Node(Restaurant newRest): left(NULL), right(NULL), rest(newRest) {}
    };
    typedef struct Node* Nodeptr;

    Nodeptr root;

    void insert_name_value(Nodeptr root, Restaurant rest);
    void insert_cuisine_value(Nodeptr root, Restaurant rest);
    void inOrderPrint(Nodeptr root);
    void preOrderPrint(Nodeptr root);
    bool containsCuisineValue(Nodeptr root, bstdata value);
    bool containsName(Nodeptr root, bstdata value);
    Nodeptr removeName(Nodeptr root, Restaurant r);
    Nodeptr removeCuisine(Nodeptr root, Restaurant r);
    void deleteTree(Nodeptr root);
    Restaurant findMin(Nodeptr root);
    void buildCuisineList(Nodeptr root, List<string> &cuisine);
    int calCuisine(string cuisine);
    void numPerCuisine(string value, Nodeptr root, int &numCuisine);

public:
    BST();
    ~BST();
    void insertName(Restaurant rest);
    void insertCuisine(Restaurant rest);
    void inOrderPrint();
    void preOrderPrint();
    bool searchName(bstdata value);
    void searchCuisine(bstdata value);
    void removeName(Restaurant r);
    void removeCuisine(Restaurant r);
    void buildCuisineList();
};

template <class bstdata>
BST<bstdata>::BST()
{
    root = NULL;
}

template <class bstdata>
BST<bstdata>::~BST()
{
    deleteTree(root);
}

template <class bstdata>
void BST<bstdata>::deleteTree(Nodeptr root)
{
    if(root)
    {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

template <class bstdata>
void BST<bstdata>::insertName(Restaurant rest)
{
    if (root == NULL)
        root = new Node(rest); //if the tree is empty insert the value at the root
    else
        insert_name_value(root, rest); //otherwise call the helper function, passing it the root
}

template <class bstdata>
void BST<bstdata>::insert_name_value(Nodeptr root, Restaurant rest)
{
    if(rest.getName() == root->rest.getName())
    {
        if(rest.getPhoneNumber() == root->rest.getPhoneNumber())
            return;
        else if(rest.getPhoneNumber() < root->rest.getPhoneNumber())
        {
            if(root->left == NULL)
                root->left = new Node(rest);
            else
                insert_name_value(root->left, rest);
        }
        else
        {
            if(root->right == NULL)
                root->right = new Node(rest);
            else
                insert_name_value(root->right, rest);
        }
    }
    else if(rest.getName() < root->rest.getName())
    {
        if(root->left == NULL)
            root->left = new Node(rest);
        else
            insert_name_value(root->left, rest);
    }
    else
    {
        if(root->right == NULL)
            root->right = new Node(rest);
        else
            insert_name_value(root->right, rest);
    }
}

template <class bstdata>
void BST<bstdata>::insertCuisine(Restaurant rest)
{
    if (root == NULL)
    {
        root = new Node(rest); //if the tree is empty insert the value at the root
    }
    else
        insert_cuisine_value(root, rest); //otherwise call the helper function, passing it the root
}


template <class bstdata>
void BST<bstdata>::insert_cuisine_value(Nodeptr root, Restaurant rest)
{
    if(rest.getCuisine() == root->rest.getCuisine())
    {
        if(rest.getPhoneNumber() == root->rest.getPhoneNumber())
            return;
        else if(rest.getPhoneNumber() < root->rest.getPhoneNumber())
        {
            if(root->left == NULL)
                root->left = new Node(rest);
            else
                insert_cuisine_value(root->left, rest);
        }
        else
        {
            if(root->right == NULL)
                root->right = new Node(rest);
            else
                insert_cuisine_value(root->right, rest);
        }

    }
    else if(rest.getCuisine() < root->rest.getCuisine())
    {
        if(root->left == NULL)
            root->left = new Node(rest);
        else
            insert_cuisine_value(root->left, rest);
    }
    else
    {
        if(root->right == NULL)
            root->right = new Node(rest);
        else
            insert_cuisine_value(root->right, rest);
    }
}

template <class bstdata>
void BST<bstdata>::inOrderPrint(Nodeptr root)
{
    if(root)
    {

        inOrderPrint(root->left);
        cout << "------------------------------------" << endl;
        cout << root->rest;
        inOrderPrint(root->right);
    }
}

template <class bstdata>
void BST<bstdata>::inOrderPrint()
{
    inOrderPrint(root);
    cout << endl;
}

template <class bstdata>
void BST<bstdata>::preOrderPrint()
{
    preOrderPrint(root);
    cout << "------------------------------------" << endl;
}

template <class bstdata>
void BST<bstdata>::preOrderPrint(Nodeptr root)
{
    if(root)
    {
        cout << "------------------------------------" << endl;
        cout << root->rest;
        preOrderPrint(root->left);
        preOrderPrint(root->right);
    }
}

template <class bstdata>
bool BST<bstdata>::containsCuisineValue(Nodeptr root, bstdata value)
{
    if(root)
    {
        string temp = root->rest.getCuisine();
        for (unsigned int i =0; i < root->rest.getCuisine().length(); i++)
            temp[i] = tolower(temp[i]);
        string valTemp = value;
        for (unsigned int i =0; i < valTemp.length(); i++)
            valTemp[i] = tolower(valTemp[i]);
        if(temp.find(valTemp) != std::string::npos)
        {
            cout << "------------------------------------" << endl;
            cout << root->rest;
        }
        containsCuisineValue(root->left, value);
        containsCuisineValue(root->right, value);
        return true;
    }
    else return false;
}

template <class bstdata>
void BST<bstdata>::searchCuisine(bstdata value)
{
    if(containsCuisineValue(root, value))
        cout << "------------------------------------" << endl;
    else
        cout << "The cuisine " << value << " could not be found." << endl;
}

template <class bstdata>
bool BST<bstdata>::searchName(bstdata value)
{
    if(root->rest.getName() == value)
        return true;
    if(root)
    {
        return containsName(root, value);
    }
    else return false;
}

template <class bstdata>
bool BST<bstdata>::containsName(Nodeptr root, bstdata value)
{
    if(root->rest.getName() == value)
        return true;
    else if(value < root->rest.getName())
    {
        if(!root->left)
            return false;
        else
            return containsName(root->left, value);
    }
    else if(value > root->rest.getName())
    {
        if(!root->right)
            return false;
        else
            return containsName(root->right, value);
    }
    return false;
}

template <class bstdata>
void BST<bstdata>::removeName(Restaurant r)
{
    if(root)
        root = removeName(root, r);
}

template <class bstdata>
typename BST<bstdata>::Nodeptr BST<bstdata>::removeName(Nodeptr root, Restaurant r)
{
    if(!root)
        return root;
    else if (r.getName() < root->rest.getName())
        root->left = removeName(root->left, r);
    else if (r.getName() > root->rest.getName())
        root->right = removeName(root->right, r);
    else if(r.getPhoneNumber() < root->rest.getPhoneNumber())
        root->left = removeName(root->left, r);
    else if(r.getPhoneNumber() > root->rest.getPhoneNumber())
        root->right = removeName(root->right, r);
    else
    {
        if (!root->left && !root->right)
        {
            Nodeptr temp = root;
            root = root->left;
            delete temp;
        }
        else if(root->left && !root->right)
        {
            Nodeptr temp = root;
            root = root->left;
            delete temp;
        }
        else if(!root->left && root->right)
        {
            Nodeptr temp = root;
            root = root->right;
            delete temp;
        }
        else
        {
            root->rest = findMin(root->right);
            root->right = removeName(root->right, findMin(root->right));
        }
    }
    return root;
}

template <class bstdata>
void BST<bstdata>::removeCuisine(Restaurant r)
{
    if(root)
        root = removeCuisine(root, r);
}

template <class bstdata>
typename BST<bstdata>::Nodeptr BST<bstdata>::removeCuisine(Nodeptr root, Restaurant r)
{
    if(!root)
        return root;
    else if (r.getCuisine() < root->rest.getCuisine())
        root->left = removeCuisine(root->left, r);
    else if (r.getCuisine() > root->rest.getCuisine())
        root->right = removeCuisine(root->right, r);
    else if(r.getPhoneNumber() < root->rest.getPhoneNumber())
        root->left = removeCuisine(root->left, r);
    else if(r.getPhoneNumber() > root->rest.getPhoneNumber())
        root->right = removeName(root->right, r);
    else
    {
        if (!root->left && !root->right)
        {
            Nodeptr temp = root;
            root = root->left;
            delete temp;
        }
        else if(root->left && !root->right)
        {
            Nodeptr temp = root;
            root = root->left;
            delete temp;
        }
        else if(!root->left && root->right)
        {
            Nodeptr temp = root;
            root = root->right;
            delete temp;
        }
        else
        {
            root->rest = findMin(root->right);
            root->right = removeName(root->right, findMin(root->right));
        }
    }
    return root;
}

template <class bstdata>
Restaurant BST<bstdata>::findMin(Nodeptr root)
{
    while(root->left)
        root = root->left;
    return root->rest;
}

template <class bstdata>
void BST<bstdata>::buildCuisineList()
{
    List<string> cuisine;
    if(root)
        cuisine.insert_tail(root->rest.getCuisine());
    buildCuisineList(root, cuisine);
    if(cuisine.start_cursor())
    {
        cout << setfill('-');
        cout << "Cuisine\t\t\t    Quantity" << endl << endl;
        while(!cuisine.off_end())
        {
            cout  << setw(30) << left << cuisine.get_cursor() << setw(3) << right << calCuisine(cuisine.get_cursor()) << endl;
            cuisine.move_cursor();
        }
    }

}

template <class bstdata>
void BST<bstdata>::buildCuisineList(Nodeptr root, List<string> &cuisine)
{
    if(root)
    {
        if(cuisine.linear_search(root->rest.getCuisine()) == -1)
            cuisine.insert_tail(root->rest.getCuisine());
        buildCuisineList(root->left, cuisine);
        buildCuisineList(root->right, cuisine);
    }
}

template <class bstdata>
int BST<bstdata>::calCuisine(string value)
{
    int num = 0;
    numPerCuisine(value, root, num);
    return num;
}

template <class bstdata>
void BST<bstdata>::numPerCuisine(string value, Nodeptr root, int &numCuisine)
{
    if(root)
    {
        if(root->rest.getCuisine() == value)
            numCuisine++;
        numPerCuisine(value, root->left, numCuisine);
        numPerCuisine(value, root->right, numCuisine);
    }
}

#endif
