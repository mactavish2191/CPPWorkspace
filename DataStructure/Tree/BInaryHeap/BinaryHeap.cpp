#include <iostream>
#include <vector>

using namespace std;
// implement a Minimum heap

template <class T>
class BinaryHeap{
public:
    explicit BinaryHeap(int capacity = 10):array(capacity), currentSize(0){ }
    explicit BinaryHeap(const vector<T> &items):array(items.size() + 10), currentSize((int)items.size())
    {
        for (int i=0; i<items.size(); ++i) {
            array[i+1] = items[i];
        }
        buildHeap();
    }
    
    bool isEmpty() const{
        if (currentSize == 0)
            return true;
        else
            return false;
    }
    
    const T& findMin() const{
        if(isEmpty()){
            cout << "Empty heap\n";
            exit(EXIT_FAILURE);
        }
        return array[1];
    }
    
    void insert(const T &x);
    void insert(T &&x);
    void deleteMin();
    void deleteMin(T &x);
    void printHeap() const;
    void makeEmpty();
    
private:
    int currentSize;
    vector<T> array;
    
    void buildHeap();
    void percolateDown(int hole);
};

template <class T>
void BinaryHeap<T>::printHeap() const{
    if(isEmpty()){
        cout << "Empty heap\n";
        return;
    }
    cout << "\n==HEAP==\n";
    for (int i=1; i<=currentSize; i++) {
        cout << array[i] << " ";
    }
    cout << "\n";
}

template <class T>
void BinaryHeap<T>::makeEmpty(){
    array.clear();
    currentSize = 0;
}

template <class T>
void BinaryHeap<T>::buildHeap(){
    for (int i = currentSize/2; i > 0; --i) {
        percolateDown(i);
    }
}

template <class T>
void BinaryHeap<T>::percolateDown(int hole){ //hole is the index at which the percolation begins
    int child;
    T tmp = move(array[hole]);
    
    for (; 2 * hole <= currentSize; hole = child) {
        child = 2 * hole;
        if(child != currentSize && array[child+1] < array[child])
            ++child;
        
        if(array[child] < tmp)
            array[hole] = move(array[child]);
        else
            break;
    }
    array[hole] = move(tmp);
}

template <class T>
void BinaryHeap<T>::insert(const T &x){
    if(currentSize == 0){
        array.resize(10);
    }
    
    if(currentSize == array.size() - 1)
        array.resize(array.size() * 2);
    
    //percolate up
    int hole = ++currentSize;
    T copy = x;
    
    array[0] = move(copy);
    for(; x < array[hole/2]; hole/=2 ){
        array[hole] = move(array[hole/2]);
    }
    array[hole] = move(array[0]);
}

template <class T>
void BinaryHeap<T>::insert(T &&x){
    if(currentSize == 0){
        array.resize(10);
    }
    
    if(currentSize == array.size() - 1)
        array.resize(array.size() * 2);
    
    //percolate up
    int hole = ++currentSize;
    
    array[0] = move(x);
    for(; x < array[hole/2]; hole/=2 ){
        array[hole] = move(array[hole/2]);
    }
    array[hole] = move(array[0]);
}

template <class T>
void BinaryHeap<T>::deleteMin(){
    if(isEmpty()){
        cout << "Empty heap\n";
        return;
    }
    
    array[1] = move(array[currentSize--]);
    percolateDown(1);
}

template <class T>
void BinaryHeap<T>::deleteMin(T &x){
    if(isEmpty()){
        cout << "Empty heap\n";
        return;
    }
    
    x = move(array[1]);
    array[1] = move(array[currentSize--]);
    percolateDown(1);
}

int main(){
    //vector<int> t = { 150, 80, 40, 30, 10, 70, 110, 100, 20, 90, 60, 50, 120, 140, 130 };
    BinaryHeap<int> H;
    H.insert(10);
    H.insert(56);
    H.insert(88);
    
    H.printHeap();
    
    return 0;
}
