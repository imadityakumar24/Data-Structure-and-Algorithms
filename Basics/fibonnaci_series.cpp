// fibonnaci series
// formula // f(n) = f(n-1) + f(n-2);

// fibbonaci series : 0 1 1 2 3 5 8 13 21.........
// index            : 0 1 2 3 4 5 6  7 8.....

// f(2) = f(1) + f(0) => 1 + 0 => 1
// f(3) = f(2) + f(1) => 1 + 1 => 2
// f(4) = f(3) + f(2) => 2 + 1 => 3

// hum is question mai index pass krenge and bolenge us index pe pda hua fibonnaci number return kardo /. it's a leetcode problem

#include <bits/stdc++.h>
using namespace std;


int fibonnaciNumber(int n){
    if(n <= 1){
        return n;
    }
       
    vector <int> array;
    array.push_back(0);
    array.push_back(1);
    for(int i = 2; i <= n; i++) {
         array.push_back(array[i - 1] + array[i - 2]);
    }

    return array[n]; // returning fibinnaci number
}


/*
int fibinnaciNumber(int n){
    if(n <= 1){
        return n;
    }
    
    int array[10];
    array[0] = 0; array[1];

    for(int i = 0; i <= n; i++) {
        array[i] = array[i-1] + array[i-2];
    }

    return array[n];
}
*/


int main() {

    int index;
    cout << "Enter the index so you get the fibbonaci number at that index : ";
    cin >> index;

    int result = fibonnaciNumber(index);
    cout << "fibonacci number is : " << result;

    return 0;
}