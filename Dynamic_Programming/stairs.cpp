#include <vector>

using namespace std;


int climbStairs(int n) {
    vector<int> mem(n + 1, 1);
    mem[0] = 1;
    mem[1] = 1;     // first step
    
    // reccurence mem[i] = mem[i - 2] + mem[i - 1], fibbonaci like
    for(int i = 2; i <= n; i++)
        mem[i] = mem[i - 2] + mem[i - 1];
    
    
    return mem[n];
}

int minCostClimbingStairs(vector<int>& cost) {
    // build from bottom up
    vector<int> mem(cost.size() + 2);
    mem[0] = 0;
    mem[1] = 0;
    
    for(int i = 2; i < cost.size() + 2; i++) {
        mem[i] = cost[i - 2] + min(mem[i - 1], mem[i - 2]);
    }
    
    return min(mem[cost.size() + 1], mem[cost.size()]);
}