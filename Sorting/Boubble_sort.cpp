
/*  // this is an not optimized code 
// because of our array is already sorted , stikk for loops ara iterating 

// boubble sort
// time complexity = O(n^2)  worst case and average 
// int his we place the max element in last postion  

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
        for(int j = 0; j < size-i; j++) {
            if(array[j] > array[j+1]) {
                // swap(array[j], array[j+1]);
                int temp = array[j+1];
                array[j+1] = array[j];
                array[j] = temp;
            }
        }
        cout << "its iterating" << endl;  // if our array is already sorted its never printed it just for understanding      
    }
    
    cout  << endl << "Sorted array is : ";
    for(int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }



    return 0;
}

*/


// optimized code 
// boubble sort
// time complexity = O(n)  best case 


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
        int swaPCount = 0;
        for(int j = 0; j < size-i-1; j++) {
            if(array[j] > array[j+1]) {
                swap(array[j], array[j+1]);   
                swaPCount = 1;             
            }
        }
        if(swaPCount == 0) {      // means if our array is already sorted need not to iterate again and again just come out out of the loops
            break;
        }
        cout << "its iterating" << endl;  // if our array is already sorted its never printed it just for understanding      
    }
    
    cout  << endl << "Sorted array is : ";
    for(int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }



    return 0;
}

