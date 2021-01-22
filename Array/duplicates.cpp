#include <vector>
#include <algorithm>
#include <set>

using namespace std;


 int findKthLargest(vector<int>& nums, int k) {
     // can also use priority queue

       std::sort(nums.begin(), nums.end());
       return nums[nums.size() - k];
}

bool containsDuplicate(vector<int>& nums) {
    // set/hashtable 


    // sort method
    if (nums.size() == 0) return false;
    std::sort(nums.begin(), nums.end());
    int prev = nums[0];
    for (int i = 1 ; i < nums.size(); i++) {
        if (nums[i] == prev) return true;
        prev = nums[i];
    }
    return false;
}