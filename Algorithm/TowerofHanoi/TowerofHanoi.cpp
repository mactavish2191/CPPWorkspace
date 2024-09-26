#include <iostream>
using namespace std;

void TowerofHanoi(int N, char From, char To, char Aux)
{
    if (N == 1) {
        cout << "Move the Disk 1 from "<< From <<" to "<<To<<"\n";
        return;
    }
    //Move the N-1 disks from A to B
    TowerofHanoi(N-1, From, Aux, To);
    
    //Move the remaining disk from A to C
    cout << "Move the Disk "<<N<<" from "<< From <<" to "<<To<<"\n";
    
    //Move the N-1 disks from B to C
    TowerofHanoi(N-1, Aux, To, From);
}

int main() {
    
    TowerofHanoi(3, 'A', 'C', 'B');
    
    return 0;
}
