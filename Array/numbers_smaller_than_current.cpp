#include <vector>

using namespace std;

// number ranges from 1 to 101; manually have an array that stores the counts
vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    vector<int> result;
    vector<int> count(101, 0);
    vector<int> cumulated(101, 0);
    
    for(auto& num : nums)
        count[num]++;
    
    for(int i = 1; i < 101; i++) 
        cumulated[i] = cumulated[i - 1] + count[i - 1];
    
    for(auto& num : nums)
        result.push_back(cumulated[num]);
    
    return result;
}

// arrays, hash tables