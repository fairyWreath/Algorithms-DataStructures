#include <vector>

using namespace std;

vector<int> findDuplicates(vector<int>& nums) {
    vector<int> res;
//         if (nums.size() == 0) return res;
    
//         int maxcount = *max_element(nums.begin(), nums.end());

//         vector<int> count(maxcount + 1, 0);
//         for(int& num : nums) {
//             if (count[num] > 0 && count[num] != -1) {
//                 res.push_back(num);
//                 count[num] = -1;
//             } 
//             else if (count[num] == 0) count[num]++;
//         }
    
    // use negative value to mark that there is a duplicate
    // the input vector is used as the 'hash table' per se
    // this work because input array is guaranteed to be positive 
    for(int& num : nums) {
        if (nums[abs(num) - 1] < 0) res.push_back(abs(num));
        else nums[abs(num) - 1] *= -1;
    }
    
    
    
    return res;
}