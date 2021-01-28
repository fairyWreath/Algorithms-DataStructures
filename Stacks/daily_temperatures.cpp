#include <vector>

using namespace std;



// stack will be emptied everytime a higher temperature is found
vector<int> dailyTemperatures(vector<int>& T) {
    vector<int> res(T.size(), 0);
    vector<int> stack;
    
    for(int i = 0; i < T.size(); i++) {
        while(!stack.empty() && T[i] > T[stack.back()]) {
            res[stack.back()] = i - stack.back();
            stack.pop_back();
        }
        stack.push_back(i);
    } 
    
    return res;
}


// arrays, hash tables