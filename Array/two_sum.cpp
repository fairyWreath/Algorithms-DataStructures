#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> res;
    
    std::unordered_map<int, int> matches;
    
    for (int x = 0; x < nums.size(); x++) {
        matches[nums[x]] = x;   
    }
    
    for (int x = 0; x < nums.size(); x++) {
    int tomatch = target - nums[x];
        if (matches.find(tomatch) != matches.end() && x != matches[tomatch])
        {
            res.push_back(matches[tomatch]);
            res.push_back(x);
            break;
        }
    }
    
    return res;
}

// related topics: array, hash tables