#include <vector>
#include <unordered_map>

using namespace std;

// xor solution
int singleNumber(vector<int>& nums) {
    int sing = 0;
    for (auto& num : nums)
        sing ^= num;
    return sing;
}



// hash table solution
int singleNumberHash(vector<int>& nums) {
    std::unordered_map<int, int> hasht;
    
    for(auto& num : nums) { 
        if (hasht.find(num) == hasht.end())
            hasht[num] = 1;
        else
            hasht[num]++;
    }
    
    for(auto itr = hasht.begin(); itr != hasht.end(); itr++) {
        if (itr->second == 1)
            return itr->first;
    }
    
    return 0;
}




/* Related Topics
Hash tables, bit manipulation
*/