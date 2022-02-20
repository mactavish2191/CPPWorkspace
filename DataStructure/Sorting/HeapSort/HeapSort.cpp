#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <utility>
#include <chrono>
using namespace std;

void Print(const vector<int> &data){
    for (auto iv: data) {
        std::cout << iv << " ";
    }
    std::cout << "\n";
}

void MaxHeapify(vector<int> &data, int &Length, int index)
{
    int left = 2*index+1;  //left value index
    int right = 2*index+2; //right value index
    int largest = index;   //parent value index
    
    if (left < Length && data[left] > data[index]) {
        largest = left;
    }
    if (right < Length && data[right] > data[largest]) {
        largest = right;
    }
    if(largest != index){
        swap(data[index], data[largest]);
        MaxHeapify(data, Length, largest);
    }
}

void BuildMaxHeap(vector<int> &data, int &Length)
{
    for (int i = (Length/2) - 1; i >= 0; i--) {
        MaxHeapify(data, Length, i);
    }
}

void HeapSort(vector<int> &data)
{
    int Length = static_cast<int>(data.size());
    BuildMaxHeap(data, Length);
    
    for (int i = Length - 1; i> 0; i--) {
        swap(data[0], data[i]);
        Length--;
        MaxHeapify(data, Length, 0);
    }
    
}
//Subsidiary function with related to Heap Operation
int HeapExtractMax(vector<int> &data, int &Length)
{
    int max = data[0];
    data[0] = data[Length - 1];
    Length--;
    MaxHeapify(data, Length, 0);
    return max;
}



void MaxHeapInsertion(vector<int> &data, int &Length, int key)
{
    Length++;
    if (Length <= data.size()) {
        data[Length-1] = key;
        BuildMaxHeap(data, Length);
    }
    else
    {
        data.push_back(key);
        BuildMaxHeap(data, Length);
    }
}

int main() {
    
    vector<int> data1{  //100 unsorted elements from 100 to 1000 range
        929, 901, 486, 943, 400, 725, 753, 731, 428, 278, 726, 968, 769, 168, 408, 762, 891, 780, 206, 409, 881, 551, 778, 528, 764,
        266, 482, 334, 161, 702, 499, 633, 342, 770, 223, 989, 423, 138, 452, 852, 647, 155, 261, 667, 559, 216, 272, 639, 376, 593,
        662, 215, 454, 855, 930, 626, 707, 811, 630, 907, 230, 752, 329, 939, 801, 661, 198, 654, 539, 109, 434, 211, 496, 574, 867,
        170, 889, 300, 768, 291, 169, 225, 743, 829, 255, 437, 617, 289, 108, 958, 479, 564, 610, 478, 256, 623, 590, 202, 122, 137
    };
    
    vector<int> data2{  //100 unsorted elements from 100 to 1000 range
        929, 901, 486, 943, 400, 725, 753, 731, 428, 278, 726, 968, 769, 168, 408, 762, 891, 780, 206, 409, 881, 551, 778, 528, 764,
        266, 482, 334, 161, 702, 499, 633, 342, 770, 223, 989, 423, 138, 452, 852, 647, 155, 261, 667, 559, 216, 272, 639, 376, 593,
        662, 215, 454, 855, 930, 626, 707, 811, 630, 907, 230, 752, 329, 939, 801, 661, 198, 654, 539, 109, 434, 211, 496, 574, 867,
        170, 889, 300, 768, 291, 169, 225, 743, 829, 255, 437, 617, 289, 108, 958, 479, 564, 610, 478, 256, 623, 590, 202, 122, 137
    };
    
    //vector<int> data3{ 5,4,9,7,19,8,17,2,6,5,21 };
        
    auto start = chrono::steady_clock::now();
    sort(data1.begin(), data1.end());
    auto end = chrono::steady_clock::now();
    auto timediff = end - start;
    cout << "Sorting STL Sort, Time elapsed :" << chrono::duration<double,micro> (timediff).count() <<"µs\n";
    Print(data1);
    
    start = chrono::steady_clock::now();
    HeapSort(data2);
    end = chrono::steady_clock::now();
    timediff = end - start;
    cout << "Sorting Heap Sort, Time elapsed :" << chrono::duration<double,micro> (timediff).count() <<"µs\n";
    Print(data2);
    
    return 0;
}
