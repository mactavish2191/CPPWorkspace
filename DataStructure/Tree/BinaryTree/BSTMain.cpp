#include <iostream>
#include "BST.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    int treeKeys[] = { 50, 76, 21, 4, 32, 64, 15, 52, 14, 100, 83, 2, 3, 70, 87, 80 };
    
    BST mytree;
    cout << "Printing the tree in order\nBefore adding numbers\n";
    
    mytree.printInOrder();
    
    for (auto i : treeKeys) {
        mytree.addLeaf(i);
    }
    
    cout << "Printing the tree in order\nAfter adding numbers\n";
    
    mytree.printInOrder();
    
    cout << endl;
    
    cout << mytree.findSmallest()<< endl;
    int input = 0;
    cout << "Enter a key value to delete. Enter -1 to stop the process.\n";
    while (input != -1) {
        cout << "Delete node: ";
        cin >> input;
        if (input != -1) {
            cout << endl;
            mytree.removeNode(input);
            mytree.printInOrder();
            cout << endl;
        }
    }
    
    return 0;
}
