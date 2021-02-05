#include <unordered_map>
#include <vector>

using namespace std;

// store count in hashtable and check that difference is only 1
int findLHS(vector<int>& nums) {
    int longest = 0;
    unordered_map<int, int> hashmap;
    
    for(auto& num : nums) {
        hashmap[num]++;
    }
    
    for(auto& entry : hashmap) {
        if (hashmap.find(entry.first + 1) != hashmap.end()) {
            if (entry.second + hashmap.find(entry.first + 1)->second > longest)
                longest = entry.second + hashmap.find(entry.first + 1)->second;
        }
    }
    
    return longest;
}

// hashtable