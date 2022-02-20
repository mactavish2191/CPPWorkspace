#include <iostream>
#include <vector>

void combinate(std::vector<int> &data, int K, int currentLength, std::vector<bool> &check, int start)
{
    if (currentLength == K) {
        //print the array
        for (int i=0; i < data.size(); i++) {
            if (check[i] == true) {
                std::cout << data[i] << " ";
            }
        }
        std::cout << "\n";
        return;
    }
    
    //base condition
    if (start == data.size())
        return;
    
    //left branching
    check[start] = true;
    combinate(data, K, currentLength+1, check, start+1);

    //right branching
    check[start] = false;
    combinate(data, K, currentLength, check, start+1);
}

void combination(std::vector<int> &data, std::vector<bool> &check, int K)
{
    combinate(data, K, 0, check, 0);
}

int main()
{
    std::vector<int> data{ 1, 2, 3, 4, 5 };
    std::vector<bool> check;
    check.reserve(data.size());
    
    combination(data, check, 3);
    
    return 0;
}
