
// Countinfg sort 
// it is used when we have range of element or if we have less numbers
// it is not comparing sort 
// tc = O(N + K)
// SC = O()


#include <bits/stdc++.h>
using namespace std;

int main() {

    vector <int> nums = { 1,0,1,1,0,2,0,1,2,0,1,0 };
    // vector <int> nums = { 11,60,1,16, 45,2,55,1,22,75,19,60 };

    cout << "Before counting sort" << endl;
    for(int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }

    int max = *max_element(nums.begin(), nums.end()); 
    int countArray[max+1] = {0};

    // frequency array or hash arraay
    for(int i = 0; i < nums.size(); i++) {
        countArray[nums[i]]++;
    }
    
    // for(int i = 0; i < max+1; i++) {
    //     cout << countArray[i] << " ";
    // }

    // updating the count array or hash array 
    for(int i = 1; i <= max; i++) {
        countArray[i] = countArray[i] + countArray[i-1];
    }

    int temp[nums.size()];
    
    for(int i = nums.size()-1; i >= 0; i--) {   // maping the values in its correct position
        temp[--countArray[nums[i]]] = nums[i];
    }

    for(int i = 0; i < nums.size(); i++) {    // 
        nums[i] = temp[i];
    }

    cout << endl << "After counting sort" << endl;
    for(int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }


    return 0;
}

