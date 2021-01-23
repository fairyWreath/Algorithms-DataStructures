#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int chtoint(char c) {
    return static_cast<int>(c - 'a');
}

// O(n) where n = word size

bool closeStrings(string word1, string word2) {
    if (word1.size() != word2.size()) return false;
    vector<int> vdiff1(26, 0);
    vector<int> vdiff2(26, 0);
    
    for (int i = 0; i < word1.size(); i++) {
        vdiff1[chtoint(word1[i])]++;
        vdiff2[chtoint(word2[i])]++;
    }
    
    vector<int> diffc1;
    vector<int> diffc2;
    
    for(int i = 0; i < 26; i++) {
        if (vdiff1[i] == 0 && vdiff2[i] != 0)     
            return false;
        if (vdiff2[i] == 0 && vdiff1[i] != 0)          
            return false;
        if (vdiff1[i] != 0)
            diffc1.push_back(vdiff1[i]);
        if (vdiff2[i] != 0)
            diffc2.push_back(vdiff2[i]);
    }
    
    sort(diffc1.begin(), diffc1.end());
    sort(diffc2.begin(), diffc2.end());

    if (diffc1 != diffc2) return false;
    
    return true;
}

int main () {
    string word1 = "abbzccca";
    string word2 = "babzzczc";

    bool res = closeStrings(word1, word2);
}


// related topics: greedy algorithms