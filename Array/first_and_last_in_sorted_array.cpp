#include <vector>
using namespace std;

// do binary searches while incrementing/decrementing the first found value

int binarys(vector<int>& nums, int start, int end, int target) {
    if (start > end) return -1;
    
    int mid = start + (end - start) / 2;
    if (nums[mid] == target) return mid;
    
    if(nums[mid] < target) return binarys(nums, mid+1, end, target);
    else return binarys(nums, start, mid-1, target);
}

vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> result(2, -1);
    int index = binarys(nums, 0, nums.size() -1 , target);
    
    if (index == -1) return result;
    
    int tempmax = index, tempmin = index;
    int max = index, min = index;
    
    while(tempmax != -1) {
        max = tempmax;
        tempmax = binarys(nums, max+1, nums.size()-1, target);
    }
    
    while(tempmin != -1) {
        min = tempmin;
        tempmin = binarys(nums, 0, min-1, target);
    }
    
    result = vector<int>{min, max};
    return result;
}


// array, binary search