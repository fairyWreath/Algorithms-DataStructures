#include <vector>

using namespace std;
// xor solution
int missingNumber(vector<int>& nums) {
        int bits = nums.size();
        for(int i = 0; i < nums.size(); i++) {
            bits ^= i;
            bits ^= nums[i];     
    }
    
    return bits;
    
}

// brute force
int missingNumber2(vector<int>& nums) {
    vector<int> counts(nums.size() + 1, 0);
    for (auto& num : nums)
        counts[num]++;
    for(int i = 0; i < counts.size(); i++) {
        if (counts[i] == 0) return i;
    }

    return 0;
}