#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

countSort(vector<int> A, int n, int pos) {
    int count[10] = {0};

    for(int i = 0; i < A.size(); i++) {
        count[ (A[i]/pos) % 10]++;
    }
}

radixSort(vector<int> nums,int n) {
    int max = *max_element(nums.begin(), nums.end());
    for(int pos = 1; max/pos > 0; pos * 10) {
        countSort(nums, n, pos);
    }
}

int main() {

    vector <int> nums = { 11,60,1,16, 45,2,55,1,22,75,19,60 };
    int n = nums.size();
    // int max = *max_element(nums.begin(), nums.end());

    return 0;
}