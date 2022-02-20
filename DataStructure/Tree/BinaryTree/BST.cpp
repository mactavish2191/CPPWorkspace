#include <iostream>
#include <cstdio>
#include "BST.h"

using namespace std;

BST::BST()
{
    root = nullptr;
}

BST::node* BST::createLeaf(int key)
{
    node* n = new node;
    n->key = key;
    n->left = nullptr;
    n->right = nullptr;
    
    return n;
}

void BST::addLeaf(int key)
{
    addLeafPrivate(key, root);
}

void BST::addLeafPrivate(int key, BST::node* Ptr)
{
    if (root == nullptr) {
        root = createLeaf(key);
    }
    else if (key < Ptr->key)
    {
        if (Ptr->left != nullptr) {
            addLeafPrivate(key, Ptr->left);
        }
        else
        {
            Ptr->left = createLeaf(key);
        }
    }
    else if (key > Ptr->key)
    {
        if (Ptr->right != nullptr) {
            addLeafPrivate(key, Ptr->right);
        }
        else
        {
            Ptr->right = createLeaf(key);
        }
    }
    else
    {
        cout << "The key "<< key << " has already been inserted to the tree."<< endl;
    }
}

void BST::printInOrder()
{
    printInOrderPrivate(root);
}

void BST::printInOrderPrivate(BST::node* Ptr)
{
    if (root != nullptr) {
        if (Ptr->left != nullptr) {
            printInOrderPrivate(Ptr->left);
        }
        cout<< Ptr->key << " ";
        if (Ptr->right != nullptr) {
            printInOrderPrivate(Ptr->right);
        }
    }
    else{
        cout << "The tree is empty.\n";
    }
    
}

BST::node* BST::returnNode(int key)
{
    return returnNodePrivate(key, root);
}

BST::node* BST::returnNodePrivate(int key, BST::node* Ptr)
{
    if (Ptr != nullptr) {
        if (Ptr->key == key) {
            return Ptr;
        }
        else{
            if (key < Ptr->key) {
                return returnNodePrivate(key, Ptr->left);
            }
            else{
                return returnNodePrivate(key, Ptr->right);
            }
        }
    }
    else
        return nullptr;
}

int BST::returnRootKey()
{
    if (root != nullptr) {
        return root->key;
    }
    else
        return -1000;
}

void BST::printChildren(int key)
{
    node* Ptr = returnNode(key);
    
    if (Ptr != nullptr) {
        cout << "Parent Node = " << Ptr->key << endl;
        
        Ptr->left == nullptr ?
        cout << "Left Child = Null\n":
        cout << "Left Child = "<< Ptr->left->key << endl;
        
        Ptr->right == nullptr ?
        cout << "Right Child = Null\n":
        cout << "Right Child = "<< Ptr->right->key << endl;
    }
    else{
        cout << "Key "<< key <<" is not in the tree\n";
    }
}

int BST::findSmallest()
{
    return findSmallestPrivate(root);
}

int BST::findSmallestPrivate(BST::node* Ptr)
{
    if (root == nullptr) {
        cout << "The tree is empty\n";
        return -1000;
    }
    else{
        if (Ptr->left != nullptr) {
            return findSmallestPrivate(Ptr->left);
        }
        else{
            return Ptr->key;
        }
    }
}

void BST::removeNode(int key)
{
    removeNodePrivate(key, root);
}

void BST::removeNodePrivate(int key, BST::node* Ptr)
{
    if (root != nullptr) {
        if (root->key == key) {
            removeRootMatch();
        }
        else{
            if (key < Ptr->key && Ptr->left != nullptr) {
                Ptr->left->key == key ?
                removeMatch(Ptr, Ptr->left, true) :
                removeNodePrivate(key, Ptr->left);
            }
            else if (key > Ptr->key && Ptr->right != nullptr) {
                Ptr->right->key == key ?
                removeMatch(Ptr, Ptr->right, false) :
                removeNodePrivate(key, Ptr->right);
            }
            else{
                cout << "The key "<< key << " was not found in the tree\n";
            }
        }
    }
    else{
        cout << "The tree is empty\n";
    }
}

void BST::removeRootMatch()
{
    if (root != nullptr) {
        node* delPtr = root;
        int rootKey = root->key;
        int smallestInRightSubTree;
        
        //Case 0 - 0 children
        if (root->left == nullptr && root->right == nullptr) {
            root = nullptr;
            delete delPtr;
        }
        
        //Case 1 - 1 child
        else if (root->left == nullptr && root->right != nullptr){
            root = root->right;
            delPtr->right = nullptr;
            delete delPtr;
            cout << "The root node with key "<< rootKey << " was deleted. "<<
            "The new root now contains key "<< root->key << endl;
        }
        else if (root->left != nullptr && root->right == nullptr){
            root = root->left;
            delPtr->left = nullptr;
            delete delPtr;
            cout << "The root node with key "<< rootKey << " was deleted. "<<
            "The new root now contains key "<< root->key << endl;
        }
        
        //Case 2 - 2 children
        else{
            smallestInRightSubTree = findSmallestPrivate(root->right);
            removeNodePrivate(smallestInRightSubTree, root);
            root->key = smallestInRightSubTree;
            cout << "The root key containing key " << rootKey << " was overwritten with key "
            << root->key << endl;
        }
    }
    else{
        cout << "Can not remove root. The tree is empty\n";
    }
}

void BST::removeMatch(BST::node *parent, BST::node *match, bool left)
{
    if (root != nullptr) {
        node* delPtr;
        int matchKey = match->key;
        int smallestInRightSubTree;
        
        //Case 0 - 0 children
        if (match->left == nullptr && match->right == nullptr) {
            delPtr = match;
            left == true ? parent->left = nullptr : parent->right = nullptr;
            delete delPtr;
            cout << "The node containing key " << matchKey << " was removed.\n";
        }
        //Case 1 - 1 children
        else if(match->left == nullptr && match->right != nullptr)
        {
            left == true ? parent->left = match->right: parent->right = match->right;
            match->right = nullptr;
            delPtr = match;
            delete delPtr;
            cout << "The node containing key " << matchKey << " was removed.\n";
        }
        else if(match->left != nullptr && match->right == nullptr)
        {
            left == true ? parent->left = match->left: parent->right = match->left;
            match->left = nullptr;
            delPtr = match;
            delete delPtr;
            cout << "The node containing key " << matchKey << " was removed.\n";
        }
        //case 2 - 2 children
        else{
            smallestInRightSubTree = findSmallestPrivate(match->right);
            removeNodePrivate(smallestInRightSubTree, match);
            match->key = smallestInRightSubTree;
        }
        
    }
    else{
        cout << "Cannot remove match. The tree is empty\n";
    }
}

