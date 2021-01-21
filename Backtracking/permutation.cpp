#include <vector>

using namespace std;


void permutePart(vector<int>& nums, vector<vector<int>>& result, vector<int>& permutation) {
    
    if (permutation.size() == nums.size()) {
        result.push_back(permutation);
        return;
    }   

    for (int j = 0; j < nums.size(); j++) {
        // if not found, add to current permutation
        if (find(permutation.cbegin(), permutation.cend(), nums[j]) == permutation.cend()) {
            permutation.push_back(nums[j]);
            permutePart(nums, result, permutation);
            
            // backtrack
            permutation.pop_back();
        }
    }
}
    
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> permutation;
    permutePart(nums, result, permutation);
    
    return result;
}