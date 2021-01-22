#include <vector>

using namespace std;

void permute(vector<int>& nums, vector<vector<int>>& result, vector<int>& perm, int index) {
    result.push_back(perm);
    
    for(int i = index; i < nums.size(); i++) {
        perm.push_back(nums[i]);
        permute(nums, result, perm, i + 1);
        perm.pop_back();
    }
}
    
    
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> perm;
    
    permute(nums, result, perm, 0);
    
    return result;
}

// related topics: backtracking, arrays, bit manipulation
