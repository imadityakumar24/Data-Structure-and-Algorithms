// selection sort pick tha samalest element and place it in first position
// select the minimum and place in starting postion
// tc = O(n^2) 
// sc = O(1)
// if already sorted : tc = o(n)
#include <iostream>
#include <vector>
using namespace std;

int main() {

    // vector <int> nums = {5,3,7,2,1};
    vector <int> nums = {2,4,5,6,7,8};
    int min = 0;
    
    for(int i = 0; i < nums.size()-1; i++) {
        // min = nums[i];
        min = i;
        for(int j = i; j < nums.size(); j++) {
            if(nums[j] < nums[min]) {
                min = j;
            }
        }

        if (min == i) {
            cout << "array is already sorted" << endl;
            break;
        }
        swap(nums[min], nums[i]);
    
    }
    
    for(auto value : nums) {
        cout << value << " ";
    }
    
    return 0;
}