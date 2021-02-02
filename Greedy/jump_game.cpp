#include <iostream>

#include <vector>

using namespace std;

bool canJump(vector<int>& nums) {
    if (nums.size() == 1) return true;
    
    vector<int> zeroes;
    for(int i = 0; i < nums.size(); i++) {
        if (nums[i] == 0 && i != nums.size() - 1) zeroes.push_back(i);  // skip 0 at end
    }
    if (zeroes.size() == 0) return true;
    for(int i = 0; i < zeroes.size(); i++) {
        if (zeroes[i] < 1) return false;            // 0 at start
        int end = 0;
        
        // check 1 by 1 to check if a jump exists
        for(int j = zeroes[i] - 1; j >= end; j--) {
            if (nums[j] + j > zeroes[i]) break;
            if (j == end) return false;
        }
    }
    
    return true;
}


int main() {
    vector<int> jump{8,2,4,4,4,9,5,2,5,8,8,0,8,6,9,1,1,6,3,5,1,2,6,6,0,4,8,6,0,3,2,8,7,6,5,1,7,0,3,4,8,3,5,9,0,4,0,1,0,5,9,2,0,7,0,2,1,0,8,2,5,1,2,3,9,7,4,7,0,0,1,8,5,6,7,5,1,9,9,3,5,0,7,5};
    bool res = canJump(jump);

    cout << "RESULT: " << res;
}