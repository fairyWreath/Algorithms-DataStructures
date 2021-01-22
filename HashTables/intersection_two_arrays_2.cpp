#include <unordered_map> //hash table
#include <vector>

using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> hasht;
    
    for(int& num : nums1) {
        if (hasht.find(num) == hasht.end()) 
            hasht[num] = 1;
        else
            hasht[num]++;
    }
    
    vector<int> result;
    
    for(int& num : nums2) {
        if (hasht.find(num) != hasht.end()) {
            if(hasht[num] > 0) {
                result.push_back(num);
                hasht[num]--;
            }
        }
    }
    
    return result;
}