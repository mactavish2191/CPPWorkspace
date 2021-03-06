#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <limits>

struct BinaryTreeNode{
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
};

BinaryTreeNode* CreateNode(int val){
    BinaryTreeNode *node = new BinaryTreeNode;
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
    if(root == nullptr){
        return;
    }
    std::stack<BinaryTreeNode *> S;
    S.push(root);
    while (S.empty() != true) {
        root = S.top(); S.pop();
        std::cout << root->data << " ";
        
        if(root->right)
            S.push(root->right);
        if(root->left)
            S.push(root->left);
    }
}

//InOrder Traversal Iterative
void printInOrderIterative(BinaryTreeNode *root){
    if(root == nullptr){
        return;
    }
    std::stack<BinaryTreeNode *> S;
    
    while (S.empty() != true || root != nullptr) {
        if(root != nullptr){
            S.push(root);
            root = root->left;
        }
        else{
            root = S.top();S.pop();
            std::cout << root->data << " ";
            root = root->right;
        }
    }
}

//PostOrder Traversal Iterative
void printPostOrderIterative(BinaryTreeNode *root){
    if(root == nullptr){
        return;
    }
    std::stack<BinaryTreeNode *> S;
    BinaryTreeNode *lastVisitedNode = nullptr;
    
    while (S.empty() != true || root != nullptr) {
        if (root != nullptr) {
            S.push(root);
            root = root->left;
        }
        else{
            BinaryTreeNode *peekNode = S.top();
            
            if (peekNode->right != nullptr && peekNode->right != lastVisitedNode) {
                root = peekNode->right;
            }
            else{
                std::cout << peekNode->data << " ";
                lastVisitedNode = peekNode; S.pop();
            }
        }
    }
    
}

void printPostOrderIterativeV2(BinaryTreeNode *root){
    if (root == nullptr) {
        return;
    }
    
    std::stack<BinaryTreeNode *> S;
    std::stack<BinaryTreeNode *> op;
    S.push(root);
    
    while (S.empty() != true) {
        root = S.top();
        op.push(root);
        S.pop();
        if (root->left) {
            S.push(root->left);
        }
        if (root->right) {
            S.push(root->right);
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
        root = Q.front();Q.pop();
        
        std::cout << root->data << " ";
        
        if (root->left) {
            Q.push(root->left);
        }
        if (root->right) {
            Q.push(root->right);
        }
    }//end while
    
}

//Recursion implementation of finding Max Element in a Tree
int FindMax_Recursive(BinaryTreeNode *root){
    int left{0}, right{0}, data{0};
    int max = std::numeric_limits<int>::min();
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
    int max = std::numeric_limits<int>::min();
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
    
    if (*root == nullptr){
        *root = CreateNode(key);
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
            temp->left = CreateNode(key);
            return;
        }
        
        if (temp->right){
            Q.push(temp->right);
        }
        else{
            temp->right = CreateNode(key);
            return;
        }
        
    }
}

//Find the size of tree recursively
int sizeR(BinaryTreeNode *root){
    if (root == nullptr) {
        return 0;
    }
    else
        return ( sizeR(root->left) + 1 + sizeR(root->right) );
}

//Find the size of tree iteratively
int sizeI(BinaryTreeNode *root){
    if (root ==  nullptr) {
        return 0;
    }
    BinaryTreeNode *temp;
    int count = 0;
    std::queue<BinaryTreeNode *> Q;
    Q.push(root);
    while (Q.empty() != true) {
        temp = Q.front();
        Q.pop();
        count++;
        if (temp->left)
            Q.push(temp->left);
        if (temp->right)
            Q.push(temp->right);
    }
    return count;
}

//print the list in reverse order
void levelOrderReverse(BinaryTreeNode *root){
    if (root == nullptr) {
        return;
    }
    
    BinaryTreeNode *temp;
    std::stack<BinaryTreeNode *> S;
    std::queue<BinaryTreeNode *> Q;
    Q.push(root);
    
    while (Q.empty() != true) {
        temp = Q.front();
        Q.pop();
        if (temp->right) {
            Q.push(temp->right);
        }
        if (temp->left) {
            Q.push(temp->left);
        }
        S.push(temp);
    }
    while (S.empty() != true) {
        std::cout << S.top()->data <<" ";
        S.pop();
    }
    std::cout << "\n";
    
}

//delete a binary tree
void deleteTree(BinaryTreeNode *root){
    if (root == nullptr) {
        return;
    }
    
    deleteTree(root->left);
    deleteTree(root->right);
    free(root);
}

//height of a tree recursively
int heightofBinaryTree(BinaryTreeNode *root){
    if (root == nullptr) {
        return 0;
    }
    
    int leftHeight = heightofBinaryTree(root->left);
    int rightHeight = heightofBinaryTree(root->right);
    
    if (leftHeight > rightHeight)
        return leftHeight+1;
    else
        return rightHeight+1;
}

//height of a tree iteratively
int heightofBinaryTreeI(BinaryTreeNode *root){
    if (root == nullptr) {
        return 0;
    }
    int level = 0;
    std::queue<BinaryTreeNode *> Q;
    Q.push(root);
    Q.push(nullptr);
    
    while (Q.empty() != true) {
        root = Q.front();
        Q.pop();
        
        //completion of current level
        if (root == nullptr) {
            //put another marker for next level
            if (Q.empty() != true) {
                Q.push(nullptr);
            }
            level++;
        }
        else
        {
            if (root->left)
                Q.push(root->left);
            if (root->right)
                Q.push(root->right);
        }
    }
    return level;
}

//algo for finding the deepest node a bianry tree
BinaryTreeNode* depthNode(BinaryTreeNode *root){
    if (root == nullptr) {
        return 0;
    }
    
    BinaryTreeNode *temp = nullptr;
    std::queue<BinaryTreeNode *> Q;
    Q.push(root);
    
    while (Q.empty() != true) {
        temp = Q.front();
        Q.pop();
        if(temp->left)
            Q.push(temp->left);
        if(temp->right)
            Q.push(temp->right);
    }
    return temp;
}

int leafCount_R(BinaryTreeNode *root){
    if (root == nullptr) {
        return 0;
    }
    if (root->left == nullptr && root->right == nullptr) {
        return 1;
    }
    else
        return leafCount_R(root->left) + leafCount_R(root->right);
}

//Leaves Count
int leafCount_I(BinaryTreeNode *root){
    if (root == nullptr) {
        return 0;
    }
    
    BinaryTreeNode *temp;
    std::queue<BinaryTreeNode *> Q;
    int count =0;
    Q.push(root);
    while (Q.empty() != true) {
        temp = Q.front();
        Q.pop();
        if (temp->left == nullptr && temp->right == nullptr) {
            count++;
        }
        if (temp->left) {
            Q.push(temp->left);
        }
        if (temp->right) {
            Q.push(temp->right);
        }
    }
    return count;
}

//Full Node Count
int fullNodeCount_I(BinaryTreeNode *root){
    if (root == nullptr) {
        return 0;
    }
    
    BinaryTreeNode *temp;
    std::queue<BinaryTreeNode *> Q;
    int count =0;
    Q.push(root);
    while (Q.empty() != true) {
        temp = Q.front();
        Q.pop();
        if (temp->left && temp->right) {
            count++;
        }
        if (temp->left) {
            Q.push(temp->left);
        }
        if (temp->right) {
            Q.push(temp->right);
        }
    }
    return count;
}

//Half Node Count(Only one node dangling)
int halfNodeCount_I(BinaryTreeNode *root){
    if (root == nullptr) {
        return 0;
    }
    
    BinaryTreeNode *temp;
    std::queue<BinaryTreeNode *> Q;
    int count =0;
    Q.push(root);
    while (Q.empty() != true) {
        temp = Q.front();
        Q.pop();
        if ((temp->left && temp->right == nullptr) || (temp->left ==nullptr && temp->right)) {
            count++;
        }
        if (temp->left) {
            Q.push(temp->left);
        }
        if (temp->right) {
            Q.push(temp->right);
        }
    }
    return count;
}

int sameTrees(BinaryTreeNode *root1, BinaryTreeNode* root2){
    if (root1 == nullptr && root2 == nullptr) {
        return 1;
    }
    if (root1 == nullptr || root2 == nullptr) {
        return 0;
    }
    
    return ( root1->data == root2->data && sameTrees(root1->left, root2->left) && sameTrees(root1->right, root2->right));
}

int levelMaxSum(BinaryTreeNode *root){
    if (root == nullptr) {
        return 0;
    }
    
    // code begins
    BinaryTreeNode *tmp;
    int level=0, maxLevel=0;
    int sum=0, maxSum=0;
    std::queue<BinaryTreeNode *> Q;
    Q.push(root);
    Q.push(nullptr);
    
    while (Q.empty() != true) {
        tmp = Q.front(); Q.pop();
        
        if (tmp == nullptr) {
            if (sum > maxSum) {
                maxSum = sum;
                maxLevel = level;
            }
            sum = 0;
            
            if (Q.empty() != true) {
                Q.push(nullptr);
            }
            level++;
        }
        else{
            sum += tmp->data;
            if (tmp->left) {
                Q.push(tmp->left);
            }
            if (tmp->right) {
                Q.push(tmp->right);
            }
        }
    }
    
    return maxLevel;
}

bool IsBT(BinaryTreeNode *root){
    if (root == nullptr) {
        return false;
    }
    
    int prev = std::numeric_limits<int>::min();
    bool isBT = true;
    std::stack<BinaryTreeNode *> S;
    
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
                isBT = false;
                break;
            }
            root = root->right;
        }
    }
    
    return isBT;
    
}

int main() {
    
    BinaryTreeNode *root = nullptr;
    Insert(&root, 1);
    Insert(&root, 2);
    Insert(&root, 3);
    Insert(&root, 4);
    Insert(&root, 5);
    Insert(&root, 6);
    Insert(&root, 7);
    //Insert(&root, 8);
    
    std::cout << std::boolalpha;
    std::cout << IsBT(root) << "\n"; 
    
//    std::cout << "Nodes :";
//    LevelOrderTraversal(root); std::cout << "\n";
//    printPreOrderIterative(root); std::cout << "\n";
//    printInOrderIterative(root); std::cout << "\n";
//    printPostOrderIterative(root); std::cout << "\n";
//    printPostOrderIterativeV2(root); std::cout << "\n";
    
//    std::cout << "Height of tree: "<< heightofBinaryTreeI(root) << "\n";
//    std::cout << "Deepest node: "<< depthNode(root)->data << "\n";
//    std::cout << "No.of leaves: "<< leafCount_I(root) << "\n";
//    std::cout << "No.of full nodes: "<< fullNodeCount_I(root) << "\n";
//    std::cout << "No.of half nodes: "<< halfNodeCount_I(root) << "\n";
//    std::cout << "Check for equality: " << sameTrees(root, root) << "\n";
//    std::cout << "Level Max Sum: " << levelMaxSum(root) << "\n";
    
    deleteTree(root);
    return 0;
}
