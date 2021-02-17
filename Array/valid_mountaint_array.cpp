#include <vector>

using namespace std;

bool validMountainArray(vector<int>& arr) {
    int prev = INT_MIN;
    bool increasing = true;

    for(int i = 0; i < arr.size(); i++) {
        int entry = arr[i];
        if (increasing) {
            if (entry == prev) return false;
            if (entry < prev) {
                if (i < 2) return false;        // if the top is the first element
                increasing = false;
            }
        }
        
        else if (entry >= prev) return false;
        
        prev = entry;
    }
    
    if (increasing) return false;
    
    return true;
}

// arrays