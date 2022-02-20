#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

static const int ALLOWED_IMBALANCE = 1;

struct AVLNode{
    int data;
    int height;
    AVLNode *left = nullptr;
    AVLNode *right = nullptr;
    
    AVLNode(int key, int h=0): data(key), height(h) { }
};

AVLNode* findMin(AVLNode *head){
    if(head == nullptr){
        return nullptr;
    }
    else if(head->left == nullptr){
        return head;
    }
    else
        return findMin(head->left);
}

AVLNode* findMax(AVLNode *head){
    if(head == nullptr){
        return nullptr;
    }
    else if(head->right == nullptr){
        return head;
    }
    else
        return findMax(head->right);
}

//Height
int height(AVLNode *head){
    return (head == nullptr) ? -1 : head->height;
}

void rotateWithLeftChild(AVLNode *&k2){ //Single Right
    AVLNode *k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    
    k2->height = 1 + std::max(height(k2->left), height(k2->right));
    k1->height = 1 + std::max(height(k1->left), k2->height);
    
    k2 = k1;
    std::cout << "Single Right\n";
}

void rotateWithRightChild(AVLNode *&k2){ //Single Left
    AVLNode *k1 = k2->right;
    k2->right = k1->left;
    k1->left = k2;
    
    k2->height = 1 + std::max(height(k2->left), height(k2->right));
    k1->height = 1 + std::max(k2->height, height(k1->right));
    
    k2 = k1;
    std::cout << "Single Left\n";
}

void doubleWithLeftChild(AVLNode *&k3){ //Left Right
    std::cout << "Left Right Double\n";
    rotateWithRightChild(k3->left);
    rotateWithLeftChild(k3);
}

void doubleWithRightChild(AVLNode *&k3){ //Right Left
    std::cout << "Right Left Double\n";
    rotateWithLeftChild(k3->right);
    rotateWithRightChild(k3);
}

//balance
void balance(AVLNode *&head){
    if(head == nullptr){
        return;
    }
    
    if( height(head->left) - height(head->right) > ALLOWED_IMBALANCE ){ //Left heavy
        if( height(head->left->left) >= height(head->left->right) ){
            rotateWithLeftChild(head); //R
        }
        else{
            doubleWithLeftChild(head); //LR
        }
    }
    else if( height(head->right) - height(head->left) > ALLOWED_IMBALANCE ){ //Right heavy
        if( height(head->right->right) >= height(head->right->left) ){
            rotateWithRightChild(head); //L
        }
        else{
            doubleWithRightChild(head); //RL
        }
    }
    
    //Re adjust height
    head->height = 1 + std::max(height(head->left), height(head->right));
}

//Insert
void insert(AVLNode *&head, int key){
    if(head == nullptr){
        head = new AVLNode(key);
        if(!head){
            std::cerr << "Memory Failed!\n";
            exit(EXIT_FAILURE);
        }
    }
    else if(key < head->data){
        insert(head->left, key);
    }
    else if(key > head->data){
        insert(head->right, key);
    }
    
    //balance the tree
    balance(head);
}

//Remove
void remove(AVLNode *&head, int key){
    if(head == nullptr){
        return;
    }
    
    if(key < head->data){
        remove(head->left, key);
    }
    else if(key > head->data){
        remove(head->right, key);
    }
    else if(head->left != nullptr && head->right != nullptr){ //2 children
        head->data = findMin(head->right)->data;
        remove(head->right, head->data);
    }
    else{ //1 child or 0
        AVLNode *oldNode = head;
        head = (head->left != nullptr) ? head->left : head->right;
        delete oldNode;
    }
    
    //balance the tree
    balance(head);
}

void printLevel(AVLNode *head){
    if(head == nullptr){
        return;
    }
    
    std::queue<AVLNode *> Q;
    Q.push(head);
    
    while(Q.empty() != true){
        head = Q.front(); Q.pop();
        std::cout << head->data << "(" << head->height << ")  ";
        
        if (head->left) {
            Q.push(head->left);
        }
        
        if (head->right) {
            Q.push(head->right);
        }
    }
    std::cout << "\n";
}


int main(int c, char **v) {
    std::vector<int> list = { 3, 2, 1, 4, 5, 6, 7, 16, 15, 14, 13, 12, 11, 10, 8, 9};
    AVLNode *root = nullptr;
    
    for(int i=0; i < list.size() ; i++){
        insert(root, list[i]);
    }
    
    printLevel(root);
    return 0;
}
