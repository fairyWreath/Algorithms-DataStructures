#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {
    int max = 0;
    int prev = 0;
    bool start = false;
    
    for(auto& price : prices) {
        if (!start) {
            prev = price;
            start = true;
        }
        if (prev >= price) {
            prev = price;
        }
        else {
            max += price - prev;
            prev = price;
        }
    }
    
    return max;
}


// arrays, greedy