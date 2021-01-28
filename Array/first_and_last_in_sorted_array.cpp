#include <vector>
using namespace std;

// do binary search, then expand from that index until different value is found
// worst case O(n)

int binarys(vector<int>& nums, int start, int end, int target) {
    if (start > end) return -1;
    
    int mid = start + (end - start) / 2;
    if (nums[mid] == target) return mid;
    
    if(nums[mid] < target) return binarys(nums, mid+1, end, target);
    else return binarys(nums, 0, mid-1, target);
}

vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> result;
    
    int index = binarys(nums, 0, nums.size() -1 , target);
    
    if(index == -1) result = vector<int>{-1, -1};
    
    int min = index, max = index;
    while(min > 0) {
        if (nums[min - 1] != target) break;
        min--;
    }
    
    while(max < nums.size() - 1) {
        if (nums[max + 1] != target) break;
        max++;
    }
    
    result = vector<int>{min, max};
    return result;
}