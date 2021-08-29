#include <iostream>
#include <stack>
#include <queue>
#include <climits>

struct BinaryTreeNode{
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
};

BinaryTreeNode* CreateNode(int val){
    BinaryTreeNode *node = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    node->data = val;
    node->left = nullptr;
    node->right =nullptr;
    return node;
}
//PreOrder Traversal Recursive
void printPreOrderRecursive(BinaryTreeNode *root){
    if (root != nullptr) {
        std::cout << root->data << " ";
        printPreOrderRecursive(root->left);
        printPreOrderRecursive(root->right);
    }
}

//InOrder Traversal Recursive
void printInOrderRecursive(BinaryTreeNode *root){
    if (root != nullptr) {
        printInOrderRecursive(root->left);
        std::cout << root->data << " ";
        printInOrderRecursive(root->right);
    }
}

//PostOrder Traversal Recursive
void printPostOrderRecursive(BinaryTreeNode *root){
    if (root != nullptr) {
        printPostOrderRecursive(root->left);
        printPostOrderRecursive(root->right);
        std::cout << root->data << " ";
    }
}

//PreOrder Traversal Iterative
void printPreOrderIterative(BinaryTreeNode *root){
    std::stack<BinaryTreeNode *> S;
    while (true) {
        while (root != nullptr) {
            //process the current node
            std::cout << root->data << " ";
            S.push(root);
            //left sub tree exist then add to stack
            root = root->left;
        }
        if (S.empty())
            break;

        root = S.top();
        S.pop();

        //left subtree completed now move to the right subtree
        root = root->right;
    }
}

//InOrder Traversal Iterative
void printInOrderIterative(BinaryTreeNode *root){
    std::stack<BinaryTreeNode *> S;
    while (true) {
        while (root != nullptr) {
            S.push(root);
            //left sub tree exist then add to stack
            root = root->left;
        }
        if (S.empty())
            break;

        root = S.top();
        S.pop();
        std::cout << root->data << " ";

        //left subtree completed now move to the right subtree
        root = root->right;
    }
}


//PostOrder Traversal Iterative
void printPostOrderIterative(BinaryTreeNode *root){
    std::stack<BinaryTreeNode *> S;
    BinaryTreeNode *init_root = root;
    int cnt{0}; bool flag = false;
    while (true) {
        while (root != nullptr && flag == false) {
            S.push(root);
            root = root->left;
        }
        if (S.empty() == true) {
            return;
        }
        if (S.top()->right == nullptr){
            root = S.top();
            S.pop();
            std::cout << root->data << " ";
            if (S.top()->right == root) {
                std::cout << S.top()->data << " ";
                S.pop();
            }
        }
        if(S.top() == init_root){
            cnt++;
        }

        if (S.empty() == false && cnt == 2) {
            std::cout << S.top()->data << " ";
            S.pop();
            flag = true;
        }
        else if(S.empty() == false ){
            root = S.top()->right;
        }
        else
            root = nullptr;

    }
}

void postOrderIterativeV2(BinaryTreeNode *root){
    if (root == nullptr) {
        return;
    }

    std::stack<BinaryTreeNode *> S;
    std::stack<BinaryTreeNode *> op;
    S.push(root);

    while (S.empty() != true) {
        BinaryTreeNode *curr = S.top();
        op.push(curr);
        S.pop();
        if (curr->left) {
            S.push(curr->left);
        }
        if (curr->right) {
            S.push(curr->right);
        }
    }

    while (op.empty() != true) {
        std::cout << op.top()->data << " ";
        op.pop();
    }

}

void LevelOrderTraversal(BinaryTreeNode *root){
    if (root == nullptr) {
        return;
    }

    std::queue<BinaryTreeNode *> Q;
    Q.push(root);

    while (Q.empty() != true) {
        BinaryTreeNode *curr = Q.front();
        Q.pop();
        std::cout << curr->data << " ";

        if (curr->left) {
            Q.push(curr->left);
        }
        if (curr->right) {
            Q.push(curr->right);
        }
    }//end while

}

//Recursion implementation of finding Max Element in a Tree
int FindMax_Recursive(BinaryTreeNode *root){
    int left{0}, right{0}, data{0};
    int max = INT_MIN;
    if (root != nullptr)
    {
        left = FindMax_Recursive(root->left);
        right = FindMax_Recursive(root->right);
        data = root->data;
        if (left > right)
            max = left;
        else
            max = right;

        if (data > max)
            max = data;
    }

    return max;
}

//Iterative implementation of finding Max Element in a Tree
int FindMax_Iterative(BinaryTreeNode *root){
    BinaryTreeNode *temp = nullptr;
    int max = INT_MIN;
    std::queue<BinaryTreeNode *> Q;
    Q.push(root);
    while(Q.empty() != true) {
        temp = Q.front();
        Q.pop();
        if (temp->data > max)
            max = temp->data;
        if (temp->left)
            Q.push(temp->left);
        if (temp->right)
            Q.push(temp->right);
    }
    return max;
}

//Find element in a Tree Recursively
int search_Recursive(BinaryTreeNode *root, int key){
    if (root == nullptr)
        return 0;

    else
    {
        //first check the current node
        if (key == root->data)
            return 1;
        else{
            //check the left node
            int temp = search_Recursive(root->left, key);
            if (temp != 0)
                return temp;
            else //check the right node
                return search_Recursive(root->right, key);
        }
    }
    return 0;
}

//Find element in a Tree Iteratively
int search_Iterative(BinaryTreeNode *root, int key){
    if (root == nullptr)
        return 0;

    BinaryTreeNode *temp;
    std::queue<BinaryTreeNode *> Q;
    Q.push(root);
    while(Q.empty() != true) {
        temp = Q.front();
        Q.pop();
        if(key == temp->data)
            return 1;
        if(temp->left)
            Q.push(temp->left);
        if(temp->right)
            Q.push(temp->right);
    }
    return 0;
}

//Insert element in a Tree using queue
void Insert(BinaryTreeNode **root, int key){
    std::queue<BinaryTreeNode *> Q;
    BinaryTreeNode *newNode = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    newNode->left = newNode->right = nullptr;
    newNode->data = key;

    if (*root == nullptr){
        *root = newNode;
        return;
    }

    Q.push(*root);
    BinaryTreeNode *temp;
    while(Q.empty() != true) {
        temp = Q.front();
        Q.pop();

        if (temp->left){
            Q.push(temp->left);
        }
        else{
            temp->left = newNode;
            return;
        }

        if (temp->right){
            Q.push(temp->right);
        }
        else{
            temp->right = newNode;
            return;
        }

    }
}


int main() {
    //create a binary tree
    // BinaryTreeNode *root = CreateNode(1);
    // root->left = CreateNode(2);
    // root->right = CreateNode(3);
    // root->left->left = CreateNode(4);
    // root->left->right = CreateNode(5);
    // root->right->left = CreateNode(6);
    // root->right->right = CreateNode(7);

    BinaryTreeNode *root = nullptr;
    Insert(&root, 1);
    Insert(&root, 2);
    Insert(&root, 3);

    LevelOrderTraversal(root);
    std::cout << "\n";


    return 0;
}
