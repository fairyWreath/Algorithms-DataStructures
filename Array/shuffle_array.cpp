#include <vector>

using namespace std;


vector<int> shuffle(vector<int>& nums, int n) {
    
    // inplace with queue
//         int backindex = n;
//         int frontprev = nums[0];
//         queue<int> q;
    
//         for(int i = 0; i < 2*n; i++) {
//             if (i % 2 != 0) {
//                 q.push(nums[i]);
//                 nums[i] = nums[backindex++];
//             }
//             else {
//                 if (q.size() > 0) {
//                     int curr = nums[i];
//                     nums[i] = q.front();
//                     q.pop();
//                     q.push(curr);
//                 }
//             }
//         }
    
    vector<int> res;
    int back = n;
    for(int i = 0; i < n; i++, back++) {
        res.push_back(nums[i]);
        res.push_back(nums[back]);
    }
    
    
    return res;
}


// arrays, two pointers