#include <bits/stdc++.h>
using namespace std;

/*
int beautifulPair(vector<int> & nums) {
    int count = 0;
    for(int i = 0; i < nums.size(); i++) {
        for(int j = i+1; j < nums.size(); j++) {
            while(nums[i] > 0 && nums[j] > 0) {
                if(nums[i] > 0) {
                    nums[i] = nums[i] % nums[j];
                }
                else {
                    nums[j] = nums[j] % nums[i];
                }
            }
            if(nums[i] == 0 && nums[j] == 1 || nums[j] == 0 && nums[i] == 1) {
                count++;
            }
        }
    }

    return count;
}
*/
int beautifulPair(vector<int>& nums) {
    int count = 0;
    for(int i = 0; i < nums.size(); i++) {
        for(int j = i + 1; j < nums.size(); j++) {
            if(__gcd(nums[i], nums[j]) == 1) {
                count++;
            }
        }
    }
    return count;
}

int main() {

   vector<int> nums = {2,5,1,4};

   int result = beautifulPair(nums);
   cout << "result = " << result;


    return 0;
}