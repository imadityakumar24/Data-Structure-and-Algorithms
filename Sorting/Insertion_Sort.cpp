/*

// insertion sort
// not optimized  code because if our array is already sorted , still our loops are iterating 
// time complexity = O(n^2)  // average and worst  case  
// best case = o(n)       // when our array will already sorted
// select the minimun and put it in the first position 



#include <bits/stdc++.h>
using namespace std;

int main() {

    
    int size = 0;
    cout << "Enter the size of array : ";
    cin >> size;
    int array[size];  
    for(int i = 0; i < size; i++) {
        cout << "Enter the array element : ";
        cin >> array[i];
    }

    for(int i = 0; i < size; i++) {
        int temp = array[i];
        int j = i-1;
        while(j >= 0 && array[j] >  temp) {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = temp;
        cout << "hello" << endl;         // for under standing 
    }
        
    
    cout  << endl << "Sorted array is : ";
    for(int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }

    return 0;
}

*/


// insertion sort
// not optimized  code because if our array is already sorted , still our loops are iterating 
// time complexity = O(n^2)  // average and worst  case  
// best case = o(n)       // when our array will already sorted
// in this we pick and element and we place it in is correct postion



#include <bits/stdc++.h>
using namespace std;

int main() {

    
    int size = 0;
    cout << "Enter the size of array : ";
    cin >> size;
    int array[size];  
    for(int i = 0; i < size; i++) {
        cout << "Enter the array element : ";
        cin >> array[i];
    }

    for(int i = 0; i < size; i++) {
        int temp = array[i];
        int j = i-1;
        int swaPCount = 0;
        while(j >= 0 && array[j] > temp) {
            array[j+1] = array[j];
            j--;
            swaPCount++;
        }
        if(swaPCount == 0) {      // means if our array is already sorted need not to iterate again and again just come out out of the loops
            break;
        }
        cout << "its iterating" << endl;  // if our array is already sorted its never printed it just for understanding     

        array[j+1] = temp;
    }
        
    
    cout  << endl << "Sorted array is : ";
    for(int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }

    return 0;
}