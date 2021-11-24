#include <iostream>
#include <stack>

//https://www.codementor.io/tucnak/Competitive-Programming-101-sv2a0p2q8

template <typename T>
class BinarySearchTree {
public:
  BinarySearchTree(): root(nullptr) {}
  BinarySearchTree(const BinarySearchTree &rhs): root(nullptr) {
    root = clone(rhs.root);
  }
  BinarySearchTree(BinarySearchTree &&rhs): root(nullptr) {
    root = clone(rhs.root);
    rhs.makeEmpty();
  }
  ~BinarySearchTree() {
    makeEmpty();
  }

  //Copy Assignment
  BinarySearchTree& operator=(const BinarySearchTree &rhs) {
    makeEmpty();
    return *(new BinarySearchTree(rhs));
  }

  //Move Assignment
  BinarySearchTree& operator=(BinarySearchTree &&rhs) {
    makeEmpty();
    return *(new BinarySearchTree(rhs));
  }


  //public member functions
  //non modifiable
  const T& findMin() const;
  const T& findMax() const;
  bool contains(const T &x) const;
  bool contains(T &&x) const;
  bool isEmpty() const;
  void printTree(std::ostream &out = std::cout) const;

  //modifiable
  void makeEmpty();
  void insert(const T &x);
  void insert(T &&x);
  void remove(const T &x);

private:

  struct BinaryNode {
    T element;
    BinaryNode *left = nullptr;
    BinaryNode *right = nullptr;

    BinaryNode(const T &x): element(x) {}
    BinaryNode(T &&x): element(std::move(x)) {}
  };

  BinaryNode *root;

  //private member functions
  // void insert(const T &x, BinaryNode *&t);
  // void insert(T &&x, BinaryNode *&t);
  // void remove(const T &x, BinaryNode *&t);
  // BinaryNode* findMin(BinaryNode *t) const;
  // BinaryNode* findMax(BinaryNode *t) const;
  // bool contains(const T &x, BinaryNode *t) const;
  // void makeEmpty(BinaryNode *&t);
  // void printTree(BinaryNode *t, std::ostream &out) const;
  // BinaryNode* clone(BinaryNode *t) const;


  BinaryNode* findMin(BinaryNode *t) const {
    if (t == nullptr)
      return nullptr;
    else if (t->left == nullptr)
      return t;
    else
      return findMin(t->left);
  }

  BinaryNode* findMax(BinaryNode *t) const {
    if (t == nullptr)
      return nullptr;
    else if (t->right == nullptr)
      return t;
    else
      return findMax(t->right);
  }

  void insert(const T &x, BinaryNode *&t) {
    if (t == nullptr) {
      t = new BinaryNode{x};
      if (!t) {
        std::cerr << "Memory Failed\n";
        exit(EXIT_FAILURE);
      }
    }
    else if (x < t->element) {
      insert(x, t->left);
    }
    else if (x > t->element) {
      insert(x, t->right);
    }
  }

  void insert(T &&x, BinaryNode *&t) {
    if (t == nullptr) {
      t = new BinaryNode{ std::move(x) };
      if (!t) {
        std::cerr << "Memory Failed\n";
        exit(EXIT_FAILURE);
      }
    }
    else if (x < t->element) {
      insert(x, t->left);
    }
    else if (x > t->element) {
      insert(x, t->right);
    }
  }

  void remove(const T &x, BinaryNode *&t) {
    if (t == nullptr) {
      return;
    }
    else if (x < t->element) {
      remove(x, t->left);
    }
    else if (x > t->element) {
      remove(x, t->right);
    }
    else if (t->left != nullptr && t->right != nullptr) { //2 children
      t->element = findMin(t->right)->element;
      remove(t->element, t->right);
    }
    else { // 0 or 1 children
      BinaryNode *oldNode = t;
      t = (t->left != nullptr) ? t->left : t->right ;
      delete oldNode;
    }
  }

  bool contains(const T &x, BinaryNode *t) const {
    if (t == nullptr) {
      return false;
    }
    else if (x < t->element) {
      return contains(x, t->element);
    }
    else if (x > t->element) {
      return conatins(x, t->element);
    }
    else {
      return true; //match
    }
  }

  void makeEmpty(BinaryNode *&t) {
    if (t == nullptr) {
      return;
    }
    else {
      makeEmpty(t->left);
      makeEmpty(t->right);
      delete t;
    }
  }

  BinaryNode* clone(BinaryNode *t) const {
    if (t == nullptr) {
      return nullptr;
    }

    BinaryNode *tmp = new BinaryNode{t->element};
    tmp->left = clone(t->left);
    tmp->right = clone(t->right);

    return tmp;
  }

  void printTree(BinaryNode *t, std::ostream &out) const {
    if (t == nullptr) {
      return;
    }

    std::stack<BinaryNode *> S;

    while (S.empty() != true || t != nullptr) {
      if (t != nullptr) {
        S.push(t);
        t = t->left;
      }
      else {
        t = S.top(); S.pop();
        out << t->element << " ";
        t = t->right;
      }
    }
    out << "\n";
  }

};

//public member functions to implement
template <typename T>
const T& BinarySearchTree<T>::findMin() const {
  BinaryNode *tmp = findMin(root);
  if (tmp == nullptr) {
    return nullptr;
  }
  else {
    return tmp->element;
  }
}

template <typename T>
const T& BinarySearchTree<T>::findMax() const {
  BinaryNode *tmp = findMax(root);
  if (tmp == nullptr) {
    return nullptr;
  }
  else {
    return tmp->element;
  }
}

template <typename T>
bool BinarySearchTree<T>::contains(const T &x) const {
  return contains(x, root);
}

template <typename T>
bool BinarySearchTree<T>::contains(T &&x) const {
  T key = std::move(x);
  return contains(key, root);
}

template <typename T>
bool BinarySearchTree<T>::isEmpty() const {
  if (root != nullptr) {
    return false;
  }
  else {
    return true;
  }
}

template <typename T>
void BinarySearchTree<T>::printTree(std::ostream &out) const {
  printTree(root, out);
}

template <typename T>
void BinarySearchTree<T>::makeEmpty() {
  makeEmpty(root);
}

template <typename T>
void BinarySearchTree<T>::insert(const T &x) {
  insert(x, root);
}

template <typename T>
void BinarySearchTree<T>::insert(T &&x) {
  insert(x, root);
}

template <typename T>
void BinarySearchTree<T>::remove(const T &x) {
  remove(x, root);
}

// Main function call
int main() {
  BinarySearchTree<int> x;
  x.insert(4);
  x.insert(2);
  x.insert(5);
  x.insert(1);
  x.insert(3);
  x.insert(6);
  x.insert(7);
  x.printTree();

  BinarySearchTree<int> y(x);
  // y.insert(40);
  // y.insert(20);
  // y.insert(50);
  // y.insert(10);
  // y.insert(30);
  // y.insert(60);
  // y.insert(70);
  y.printTree();

  // x = y;
  // x.printTree();

  return 0;
}