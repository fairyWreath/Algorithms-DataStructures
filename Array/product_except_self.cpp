#include <vector>

using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> output(nums.size(), 1);
    int leftmult = 1;
    int rightmult = 1;
    
    // calculate product from front
    for(int i = 0; i < nums.size(); i++) {
        output[i] *= leftmult;
        leftmult *= nums[i];
    }
    
    // product from the back
    for(int j = nums.size() - 1; j >= 0; j--) {
        output[j] *= rightmult;
        rightmult *= nums[j];
    }
    
    
    
    
    return output;
}