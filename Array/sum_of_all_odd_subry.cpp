#include <vector>

using namespace std;

int sumOddLengthSubarrays(vector<int>& arr) {
    int res = 0;
    
    // brute force
    for(int i = 0; i < arr.size(); i++)
    {
        int curr = 0;
        for(int j = i; j < arr.size(); j++) {
            curr += arr[j];
            if ((j-i)%2 == 0) res += curr;
        }
    }
    
    return res;
}