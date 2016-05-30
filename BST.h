#ifndef _BST_H_
#define _BST_H_

#include <iostream>
#include <fstream>
#include "Restaurant.h"

using namespace std;

template <class bstdata>
class BST
{
private:
    struct Node
    {
            Node* left;
            Node* right;
            bstdata data;

            Node(): left(NULL), right(NULL), data(){}
            Node(bstdata newRest): left(NULL), right(NULL), data(newRest){}
    };

    typedef struct Node* Nodeptr;

    Nodeptr root;

    /**Private helper functions*/

    void insert_name_value(Nodeptr root, Restaurant rest);
    void insert_cuisine_value(Nodeptr root, Restaurant rest);
    void inOrderPrint(Nodeptr root);
    void preOrderPrint(Nodeptr root);
    //bool containsValue(Nodeptr root, bstdata value);
    bool containsCuisine(Nodeptr root, string cuisine);
    Nodeptr removeName(Nodeptr root, bstdata value);
    Nodeptr removeCuisine(Nodeptr root, bstdata data);
    void deleteTree(Nodeptr root);
    int getHeight(Nodeptr root);
    bstdata findMin(Nodeptr root);
    void printCuisine(Nodeptr root, string cuisine);

public:
    BST();
    ~BST();
    bool is_empty();
    void insertName(Restaurant rest);
    void insertCuisine(Restaurant rest);
    void inOrderPrint();
    void preOrderPrint();
    //bool search(bstdata value);
    void searchCuisine(string cuisine);
    void removeName(bstdata value);
    void removeCuisine(bstdata data);

    bool isEmpty();
    int getHeight();
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
    if(rest.getName() == root->data.getName())
    {
        if(rest.getPhoneNumber() == root->data.getPhoneNumber())
            return;
        else if(rest.getPhoneNumber() < root->data.getPhoneNumber())
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
    else if(rest.getName() < root->data.getName())
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
        root = new Node(rest); //if the tree is empty insert the value at the root
    else
        insert_cuisine_value(root, rest); //otherwise call the helper function, passing it the root

}

template <class bstdata>
void BST<bstdata>::insert_cuisine_value(Nodeptr root, Restaurant rest)
{
    if(rest.getCuisine() == root->data.getCuisine())
    {
        if(rest.getPhoneNumber() == root->data.getPhoneNumber())
            return;
        else if(rest.getPhoneNumber() < root->data.getPhoneNumber())
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
    else if(rest.getCuisine() < root->data.getCuisine())
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
        cout << root->data;
        inOrderPrint(root->right);
    }
}

template <class bstdata>
void BST<bstdata>::inOrderPrint()
{
    inOrderPrint(root);
    cout << "------------------------------------" << endl;
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
        cout << root->data;
        preOrderPrint(root->left);
        preOrderPrint(root->right);
	}
}

/*template <class bstdata>	// we dont need this function
bool BST<bstdata>::containsValue(Nodeptr root, bstdata value)
{
    if(root->data == value)
        return true;
    else if(value < root->data)
    {
        if(!root->left)
            return false;
        else
            return containsValue(root->left, value);
    }
    else if(value > root->data)
    {
        if(!root->right)
            return false;
        else
            return containsValue(root->right, value);
    }
    return false;
}*/

/*template <class bstdata>
bool BST<bstdata>::search(bstdata value)
{
    if(root->data == value)
        return true;
    else if(root)
        return containsValue(root, value);
    else return false;
}*/

template <class bstdata>
void BST<bstdata>::removeName(bstdata value)
{
	// dont need any precondition
    if(root)
        root = removeName(root, value);
}

template <class bstdata>
typename BST<bstdata>::Nodeptr BST<bstdata>::removeName(Nodeptr root, bstdata value)
{
    if(!root)
        return root;
    else if (value.getName() < root->data.getName())
        root->left = removeName(root->left, value);
    else if (value.getName() > root->data.getName())
        root->right = removeName(root->right, value);
	else if(value.getPhoneNumber() < root->data.getPhoneNumber())
		root->left = removeName(root->left, value);
	else if(value.getPhoneNumber() > root->data.getPhoneNumber())
		root->right = removeName(root->right, value);
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
            root->data = findMin(root->right);
            root->right = removeName(root->right, findMin(root->right));
        }
    }
    return root;
}

template <class bstdata>
void BST<bstdata>::removeCuisine(bstdata data)
{
	if(root)
		root = removeCuisine(root, data);
}

template <class bstdata>
typename BST<bstdata>::Nodeptr BST<bstdata>::removeCuisine(Nodeptr root, bstdata data)
{
	if(!root)
		return root;
    else if (data.getCuisine() < root->data.getCuisine())
        root->left = removeCuisine(root->left, data);
    else if (data.getCuisine() > root->data.getCuisine())
        root->right = removeCuisine(root->right, data);
	else if(data.getPhoneNumber() < root->data.getPhoneNumber())
		root->left = removeCuisine(root->left, data);
	else if(data.getPhoneNumber() > root->data.getPhoneNumber())
		root->right = removeName(root->right, data);
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
            root->data = findMin(root->right);
            root->right = removeName(root->right, findMin(root->right));
        }
    }
    return root;
}

template <class bstdata>
bool BST<bstdata>::isEmpty()
{
    return root == NULL;
}

template <class bstdata>
int BST<bstdata>::getHeight(Nodeptr root)
{

    int height = 0;
    if(root)
    {
        if(root->left || root->right)
        {
            int leftHeight = 0;
            int rightHeight = 0;
            if(root->left)
            {
                leftHeight = getHeight(root->left);
            }
            if(root->right)
            {
                rightHeight = getHeight(root->right);
            }
            if(rightHeight < leftHeight)
                height = leftHeight + 1;
            else
                height = rightHeight + 1;
        }
    }
    return height;

}

template <class bstdata>
int BST<bstdata>::getHeight()
{
    int height;
    if(root)
        height = getHeight(root);
    return height;
}

template <class bstdata>
bstdata BST<bstdata>::findMin(Nodeptr root)
{
    while(root->left)
        root = root->left;
    return root->data;
}

template <class bstdata>
void BST<bstdata>::searchCuisine(string cuisine)
{
	if(containsCuisine(root, cuisine))
		printCuisine(root, cuisine);
	else
		cout << "searchCuisine(): No such cuisine in the database." << endl;
}

template <class bstdata>
bool BST<bstdata>::containsCuisine(Nodeptr root, string cuisine)
{
	if(root->data.getCuisine() == cuisine)
		return true;
    else if(cuisine < root->data.getCuisine())
    {
        if(!root->left)
            return false;
        else
            return containsCuisine(root->left, cuisine);
    }
    else
    {
        if(!root->right)
            return false;
        else
            return containsCuisine(root->right, cuisine);
    }
    return false;
}

template <class bstdata>
void BST<bstdata>::printCuisine(Nodeptr root, string cuisine)
{
	if(root)
	{
		printCuisine(root->left, cuisine);
		if(root->data.getCuisine() == cuisine)
		{
			cout << "------------------------------------" << endl;
			cout << root->data;
		}
		printCuisine(root->right, cuisine);

	}
}

#endif




