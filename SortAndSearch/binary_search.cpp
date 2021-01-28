#include <vector>

using namespace std;

int binarys(vector<int>& nums, int target, int start, int end) {
    if (end < start) return -1;
    int mid = start + (end - start) / 2;
    if (nums[mid] == target) return mid;
    if (nums[mid] < target) return binarys(nums, target, mid+1, end);
    else return binarys(nums, target, start, mid-1);
}

int search(vector<int>& nums, int target) {
    return binarys(nums, target, 0, nums.size() - 1);    
}