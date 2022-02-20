#include <iostream>
#include <vector>
#include <stack>
#include <limits>

using namespace std;

struct Node{
    int data =0;
    Node *left = nullptr;
    Node *right = nullptr;
    Node(int value):data(value) {}
};

Node* insert_node(Node *&root, int key){
    if(root == nullptr){
        root = new Node(key);
        if(!root){
            cerr << "Memory failed\n";
            exit(EXIT_FAILURE);
        }
    }
    else{
        if(key < root->data){
            root->left = insert_node(root->left, key);
        }
        else if(key > root->data){
            root->right = insert_node(root->right, key);
        }
    }
    
    return root;
}

void insert(Node *&root, int key){
    root = insert_node(root, key);
}

Node* find(Node *root, int key){
    if(root == nullptr)
        return nullptr;
    else if (key < root->data)
        return find(root->left, key);
    
    else if (key > root->data)
        return find(root->right, key);
    
    return root;
}

Node* findI(Node *root, int key){
    if(root == nullptr)
        return nullptr;
    while (root != nullptr) {
        if(key == root->data)
            return root;
        else if(key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return nullptr;
}

void printInorder(Node *root){
    if(root == nullptr)
        return;
    else{
        printInorder(root->left);
        cout << root->data << " ";
        printInorder(root->right);
    }
}

//find the minimim element on the left most branch of the tree
Node* minElement(Node *root){
    if(root == nullptr){
        return nullptr;
    }
    else if(root->left == nullptr){
        return root;
    }
    else{
        return minElement(root->left);
    }
}

//find the maximim element on the right most branch of the tree
Node* maxElement(Node *root){
    if(root == nullptr){
        return nullptr;
    }
    else if(root->right == nullptr){
        return root;
    }
    else{
        return maxElement(root->right);
    }
}

void remove(Node * &root, int key){
    if(root == nullptr)
        return;
    else if(key < root->data)
        remove(root->left, key);
    else if(key > root->data)
        remove(root->right, key);
    else if(root->left != nullptr && root->right != nullptr){
        root->data = minElement(root->right)->data;
        remove(root->right, root->data);
    }
    else{
        Node *oldNode = root;
        root = (root->left != nullptr) ? root->left : root->right;
        delete oldNode;
    }
}

//Auxillary functions

//Lowest Common Ancestor
Node* LCA(Node *root, Node *alpha, Node *beta){
    while(true){
        if ((alpha->data < root->data && beta->data > root->data) || (alpha->data > root->data && beta->data < root->data)) {
            return root;
        }
        if(alpha->data < root->data){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
}

bool IsBST(Node *root){
    if (root == nullptr) {
        return false;
    }
    
    int prev = numeric_limits<int>::min();
    bool isBST = true;
    stack<Node *> S;
    
    while (S.empty() != true || root != nullptr) {
        if (root != nullptr) {
            S.push(root);
            root = root->left;
        }
        else{
            root = S.top(); S.pop();
            if(root->data > prev){
                prev = root->data;
            }
            else{
                isBST = false;
                break;
            }
            root = root->right;
        }
    }
    
    return isBST;
    
}

void preOrder(Node *root){
    if(root == nullptr)
        return;
    
    stack<Node *> S;
    S.push(root);
    
    while(S.empty() != true){
        root = S.top(); S.pop();
        cout << root->data << " ";
        
        if (root->right) {
            S.push(root->right);
        }
        
        if (root->left) {
            S.push(root->left);
        }
    }
}

void inOrder(Node *root){
    if (root == nullptr) {
        return;
    }
    
    stack<Node *> S;
    
    while (S.empty() != true || root != nullptr) {
        if (root != nullptr) {
            S.push(root);
            root = root->left;
        }
        else{
            root = S.top(); S.pop();
            cout << root->data << " ";
            root = root->right;
        }
    }
}

void postOrder(Node *root){
    if (root == nullptr) {
        return;
    }
    
    stack<Node *> S;
    Node *lastNodeVisit  = nullptr;
    
    while (S.empty() != true || root != nullptr) {
        if (root != nullptr) {
            S.push(root);
            root = root->left;
        }
        else{
            Node *peekNode = S.top();
            
            if (peekNode->right != nullptr && peekNode->right != lastNodeVisit) {
                root = peekNode->right;
            }
            else{
                cout << peekNode->data << " ";
                lastNodeVisit = S.top(); S.pop();
            }
        }
    } // end while
}

Node* make_BST(int A[], int left, int right){
    if (left > right) {
        return nullptr;
    }
    
    if (left == right) {
        Node *node = new Node(A[left]);
        return node;
    }
    else{
        int mid = left + (right - left)/2;
        Node *node = new Node(A[mid]);
        node->left = make_BST(A, left, mid - 1);
        node->right = make_BST(A, mid + 1, right);
        return node;
    }
}

void build_BST(Node **node, int A[], int left, int right){
    *node = make_BST(A, left, right);
}

int main(int argc, const char * argv[]) {
    
    vector<int> list{ 6, 2, 8, 1, 5, 3, 4 };
    //int A[] = { 5, 8, 13, 18, 34, 40, 56, 60, 75, 90 };
    
    Node *root = nullptr;
    //build_BST(&root, A, 0, 9);
    //inOrder(root); cout << "\n";
    
    //Node *root = nullptr;
    for(auto &l : list){
        insert(root, l);
    }
    
    inOrder(root); cout << "\n";
    remove(root, 4);
    inOrder(root); cout << "\n";
    
    return 0;
}
