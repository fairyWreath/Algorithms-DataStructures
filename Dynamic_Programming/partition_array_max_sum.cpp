#include <vector>

using namespace std;

int maxSumAfterPartitioning(vector<int>& arr, int k) {
    vector<int> mem(arr.size() + 1, 0);
    
    // check max from last k values, i - k to i; others are already cutt of
    // mem[i] is that max * k + mem[i - k] of the previous max solution
    for(int i = 1; i < arr.size() + 1; i++) {
        int currmax = 0;
        for(int j = 1; j <= k && i - j + 1 >= 1; j++) {
            currmax = max(currmax, arr[i - j]);
            mem[i] = max(mem[i], mem[i - j] + currmax * j);
        }
        
    }
    
    return mem[arr.size()];
}