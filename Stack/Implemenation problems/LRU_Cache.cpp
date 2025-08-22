/*

146. LRU Cache
Solved
Medium
Topics
premium lock icon
Companies
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.

 

Example 1:

Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4
 

Constraints:

1 <= capacity <= 3000
0 <= key <= 104
0 <= value <= 105
At most 2 * 105 calls will be made to get and put.
 
Seen this question in a real interview before?
1/5
Yes
No
Accepted
2,228,345/4.9M
Acceptance Rate
45.7%

*/




/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */





#include <bits/stdc++.h>
using namespace std;

/*
// brute force solution givign TLE
// Erase takes o(n) time 
// tc = O(n + o(n))
// sc = O(n)
class LRUCache {
public:
    vector <pair<int, int> > cache;
    int n;
    LRUCache(int capacity) {
        n = capacity;
    }
    
    int get(int key) {
        for (int i = 0; i < cache.size(); i++) {
            if (cache[i].first == key) {
                int value = cache[i].second;

                pair <int, int> temp = cache[i];
                cache.erase(cache.begin() + i);
                cache.push_back(temp);

                return value;
            }
        }
        return -1;
    }
    
    void put(int key, int value) {
        for (int i = 0; i < cache.size(); i++) {
            if (cache[i].first == key) {
                cache.erase(cache.begin() + i);
                pair <int, int> temp = {key, value};
                cache.push_back(temp);
                return;
            }
        }

        if (cache.size() == n) {
            cache.erase(cache.begin());
            pair <int, int> temp = {key, value};
            cache.push_back(temp);
        }
        else {
            pair <int, int> temp = {key, value};
            cache.push_back(temp);
        }
    }
};
*/



/*
// Optimal solution using Doubly linked list and map
// tc = 
// sc =
class LRUCache {
public:
    list <int> dll;
    // map <int, pair <int, int>>
    map<int, pair< list<int>::iterator, int>> mp; //key->(list_node, value)
    int n;
    LRUCache(int capacity) {
        n = capacity;
    }
    
    void markRecentlyUsed(int key) {
        dll.erase(mp[key].first);

        dll.push_front(key);   
        mp[key].first = dll.begin();     
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;    
        }
        markRecentlyUsed(key); 
        return mp[key].second;
    }
    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            mp[key].second = value;
            markRecentlyUsed(key); 
        }
        else {
            dll.push_front(key);
            mp[key] = {dll.begin(), value};
            n--;    
        }

        if (n < 0) {
            int keytOBeDeleted = dll.back();
            mp.erase(keytOBeDeleted);
            dll.pop_back();
            n++;
        }
    }
};
*/



// Optimal solution watched codestory video to undestand it
// New key → you directly insert at front (already recently used).
// Existing key → you must erase its old position and reinsert at front (hence markRecentlyUsed).
// Time Complexity:
// LRUCache (Constructor): O(1)
// markRecentlyUsed: O(1)
// get: O(logN) (due to std::map operations)
// put: O(logN) (due to std::map operations)
// Note: If std::unordered_map were used instead of std::map, get and put would be O(1) on average.
// Space Complexity:
// O(capacity)
class LRUCache {        
public:
    list <int> dll;
    //   key         address of node     value     
    map <int, pair< list<int>::iterator, int>> mp;
    int n = 0;
    LRUCache(int capacity) {
       n = capacity;
    }

    void markRecentlyUsed(int key) {
        dll.erase(mp[key].first);           // mp[key.first] give the addred of node which is to be delted  
        dll.push_front(key);                // takes o(1) time
        mp[key].first = dll.begin();
    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        markRecentlyUsed(key);
        return mp[key].second;
    }
    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            mp[key].second = value;
            markRecentlyUsed(key);
        }
        else {
            dll.push_front(key);
            mp[key] = {dll.begin(), value};
            n--;
        }

        if (n < 0) {
            int keyDeleted = dll.back();
            mp.erase(keyDeleted);
            dll.pop_back();
            n++;
        }

    }
};


