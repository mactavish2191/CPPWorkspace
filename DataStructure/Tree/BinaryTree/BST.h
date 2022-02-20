#ifndef BST_h
#define BST_h

class BST
{
private:
    struct node
    {
        int key;
        node* left;
        node* right;
    };
    
    node* root;
    void addLeafPrivate(int key, node* Ptr);
    void printInOrderPrivate(node* Ptr);
    node* returnNodePrivate(int key, node* Ptr);
    int findSmallestPrivate(node* Ptr);
    void removeNodePrivate(int key, node* Ptr);
    void removeRootMatch();
    void removeMatch(node* parent, node* match, bool left);
    
public:
    BST();
    node* createLeaf(int key);
    void addLeaf(int key);
    void printInOrder();
    node* returnNode(int key);
    int returnRootKey();
    void printChildren(int key);
    int findSmallest();
    void removeNode(int key);
};


#endif /* BST_h */
