#include <iostream>
using namespace std;

void printArray(int n);

int array[7] = {2,4,8,10,15,20,66};

int main() {

   // int array[7] = {2,4,8,10,15,20,66};

    printArray(7);

 /*   
void printArray(int n) {
    printArray(n-1);
    cout << array[n] << " ";
}
*/

    return 0;
}

void printArray(int n) {
    if(n < 0) 
        return;
    printArray(n-1);
    cout << array[n] << " ";
}