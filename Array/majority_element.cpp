#include <vector>
#include <unordered_map>

using namespace std;

int majorityElement(vector<int>& nums) {
    unordered_map<int, int> map;
    for(int& num : nums) {
        if (map.find(num) == map.end())
            map[num] = 1;
        else 
            map[num]++;
        if (map[num] > nums.size() / 2)
                return num;
    }
    return 0;
}

// related topics: array, divide and conquer, bit manipulation