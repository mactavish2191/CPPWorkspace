#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <chrono>
using namespace std;

void Print(const vector<int> &data){
    for (auto iv: data) {
        std::cout << iv << " ";
    }
    std::cout << "\n";
}

void merge(vector<int> &left, vector<int> &right, vector<int> &data)
{
    int i,j,k;
    i=j=k=0;
    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            data[k] = left[i]; i++;
        }
        else{
            data[k] = right[j]; j++;
        }
        k++;
    }
    while (i < left.size()){
        data[k] = left[i]; k++; i++;
    }
    while (j < right.size()) {
        data[k] = right[j]; k++; j++;
    }
    
}

void mergeSort(vector<int> &data)
{
    if (data.size() < 2)
        return;
    
    int mid = static_cast<int>(data.size() / 2);
    vector<int> left, right;
    left.reserve(mid);
    right.reserve(data.size() - mid);
    
    for (int i=0; i < mid; i++) {
        left[i] = data[i];
    }
    for (int i = mid; i < data.size(); i++) {
        right[i - mid] = data[i];
    }
        
    mergeSort(left);
    mergeSort(right);
    merge(left, right, data);
    
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
    
    auto start = chrono::steady_clock::now();
    sort(data1.begin(), data1.end());
    auto end = chrono::steady_clock::now();
    auto timediff = end - start;
    cout << "Sorting STL Sort, Time elapsed :" << chrono::duration<double,micro> (timediff).count() <<"µs\n";
    Print(data1);
    
    start = chrono::steady_clock::now();
    mergeSort(data2);
    end = chrono::steady_clock::now();
    timediff = end - start;
    cout << "Searching Merge Sort, Time elapsed :" << chrono::duration<double,micro> (timediff).count() <<"µs\n";
    Print(data2);
    
    return 0;
}

