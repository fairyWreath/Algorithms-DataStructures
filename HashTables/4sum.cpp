#include <vector>
#include <unordered_map>

using namespace std;

// O(n^2) time O(n) space

int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {  
    unordered_map<int, int> hasht;
    int count = 0;
    
    // generate possible from first two
    for(int& a : A)
        for (int&b : B)
            hasht[a + b]++;
    
    // from last two get matches
    for(int& c : C)
        for (int&d : D)
            count += hasht[(c+d)*-1];
    
    
    return count;
}

// related topics: hash tables, binary search