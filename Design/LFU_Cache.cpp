/*

460. LFU Cache
Solved
Hard
Topics
premium lock icon
Companies
Design and implement a data structure for a Least Frequently Used (LFU) cache.

Implement the LFUCache class:

LFUCache(int capacity) Initializes the object with the capacity of the data structure.
int get(int key) Gets the value of the key if the key exists in the cache. Otherwise, returns -1.
void put(int key, int value) Update the value of the key if present, or inserts the key if not already present. When the cache reaches its capacity, it should invalidate and remove the least frequently used key before inserting a new item. For this problem, when there is a tie (i.e., two or more keys with the same frequency), the least recently used key would be invalidated.
To determine the least frequently used key, a use counter is maintained for each key in the cache. The key with the smallest use counter is the least frequently used key.

When a key is first inserted into the cache, its use counter is set to 1 (due to the put operation). The use counter for a key in the cache is incremented either a get or put operation is called on it.

The functions get and put must each run in O(1) average time complexity.

 

Example 1:

Input
["LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [3], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, 3, null, -1, 3, 4]

Explanation
// cnt(x) = the use counter for key x
// cache=[] will show the last used order for tiebreakers (leftmost element is  most recent)
LFUCache lfu = new LFUCache(2);
lfu.put(1, 1);   // cache=[1,_], cnt(1)=1
lfu.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
lfu.get(1);      // return 1
                 // cache=[1,2], cnt(2)=1, cnt(1)=2
lfu.put(3, 3);   // 2 is the LFU key because cnt(2)=1 is the smallest, invalidate 2.
                 // cache=[3,1], cnt(3)=1, cnt(1)=2
lfu.get(2);      // return -1 (not found)
lfu.get(3);      // return 3
                 // cache=[3,1], cnt(3)=2, cnt(1)=2
lfu.put(4, 4);   // Both 1 and 3 have the same cnt, but 1 is LRU, invalidate 1.
                 // cache=[4,3], cnt(4)=1, cnt(3)=2
lfu.get(1);      // return -1 (not found)
lfu.get(3);      // return 3
                 // cache=[3,4], cnt(4)=1, cnt(3)=3
lfu.get(4);      // return 4
                 // cache=[4,3], cnt(4)=2, cnt(3)=3
 

Constraints:

1 <= capacity <= 104
0 <= key <= 105
0 <= value <= 109
At most 2 * 105 calls will be made to get and put.
 

 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
324,921/687.7K
Acceptance Rate
47.2%

*/





#include <bits/stdc++.h>
using namespace std;

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


// watched codestory video
// Time Complexity
// get: O(1)
// put: O(1) average, O(log n) when eviction needed
// Space Complexity: O(cap)

class LFUCache {
public:

    int cap;
    int size;
    // unordered_map<int, address> mp;     //key -> address of list of vector{key, value, freq}
    unordered_map<int, list<vector<int>>::iterator> mp; //key -> address of list of vector{key, value, freq}   
    map <int, list<vector<int>>> freq;  //freq -> list of vector{key, value, freq}

    LFUCache(int capacity) {
        cap = capacity;
        size = 0;
    }

    void  makeMostFreqUsed(int key) {
        auto &vec = *(mp[key]);
        int value = vec[1];
        int f     = vec[2];

        freq[f].erase(mp[key]);
        
        if(freq[f].empty())
            freq.erase(f);
        
        f++;
        freq[f].push_front(vector<int>({key, value, f}));
        mp[key] = freq[f].begin();    
    }
    
    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        auto &vec = (*(mp[key]));    // node address  
        int value = vec[1];
        makeMostFreqUsed(key);
        return value;
    }
    
    void put(int key, int value) {
        if (cap == 0) 
            return;

        if (mp.find(key) != mp.end()) {
            auto &vec = (*(mp[key])); 
            vec[1] = value;
            makeMostFreqUsed(key);
        }    
        else if (size < cap) {
            size++;
            // new aaya hai
            freq[1].push_front(vector<int>({key, value, 1}));
            mp[key] = freq[1].begin();
        }
        else {
            //Time to remove LFU or LRU if tie
            auto &kaunSaList = freq.begin()->second;
            int ketToDelete = (kaunSaList.back())[0];
            kaunSaList.pop_back();

            if (kaunSaList.empty()) {
                freq.erase(freq.begin()->first);
            }

            freq[1].push_front(vector<int>({key, value, 1}));
            mp.erase(ketToDelete);
            mp[key] = freq[1].begin();
        }
            
    }
};


/*
class LFUCache {
private:
    int cap;
    int size;
    unordered_map<int, list<vector<int>>::iterator> mp; //key -> address of list of vector{key, value, freq}
    map<int, list<vector<int>>> freq; //freq -> list of vector{key, value, freq}
    
public:
    LFUCache(int capacity) {
        cap = capacity;
        size = 0;
    }
    
    void makeMostFrequentlyUsed(int key) {
        auto &vec = *(mp[key]);
        
        int value = vec[1];
        
        int f     = vec[2];
        
        freq[f].erase(mp[key]);
        
        if(freq[f].empty())
            freq.erase(f);
        
        f++;
        
        freq[f].push_front(vector<int>({key, value, f}));
        
        mp[key] = freq[f].begin();
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end())
            return -1;
        
        auto &vec = (*(mp[key]));
        
        int value = vec[1];
        
        makeMostFrequentlyUsed(key);
        
        return value;
    }
    
    void put(int key, int value) {
        if(cap == 0)
            return;
        
        if(mp.find(key) != mp.end()) {
            auto &vec = (*(mp[key]));
            vec[1] = value;
            makeMostFrequentlyUsed(key);
        }
        else if(size < cap) {
            size++;
            freq[1].push_front(vector<int>({key, value, 1}));
            mp[key] = freq[1].begin();
        }
        else { //Time to remove LFU or LRU if tie
            
            auto &kaun_sa_list = freq.begin()->second;
            
            int key_delete = (kaun_sa_list.back())[0]; //ordered_map ensures that the begin() will be th eleast frequency
            
            kaun_sa_list.pop_back();
            
            if(kaun_sa_list.empty())
                freq.erase(freq.begin()->first);
            
            freq[1].push_front(vector<int>({key, value, 1}));
            
            mp.erase(key_delete);
            mp[key] = freq[1].begin();
        }
    }
};
*/

