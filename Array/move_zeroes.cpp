#include <iostream>
#include <vector>

using namespace std;

void moveZeroes(vector<int>& nums) {
    int total = 0;
    int currindex = 0;
    for(int i = 0; i < nums.size(); i++) {      
        if (nums[i] == 0) {
            total++;
            continue;
        }

        if (total > 0) {
            nums[currindex] = nums[currindex + total]; 
        }
            currindex++;
    }

    for(int i = nums.size() - total; i < nums.size(); i++) {
        nums[i] = 0;
    }
}

int main() {
    vector<int> nums {0,1,0,3,12};
    moveZeroes(nums);

    for(auto& num : nums)
        cout << num;
}

// related topics: arrays, two pointers