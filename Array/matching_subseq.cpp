#include <vector>
#include <string>


using namespace std;

int numMatchingSubseq(string s, vector<string>& words) {
    int res = 0;
    // use 2d vector as hashmap, can be better
    vector<vector<int>> counts(26, vector<int>());
    
    for(int i = 0; i < s.length(); i++) {
        counts[s[i] - 'a'].push_back(i);
    }
    
    bool flag = false;
    for(auto& word : words) {
        int currlast = -1;
        
        for(int i = 0; i < word.length(); i++) {
            if (counts[word[i] - 'a'].size() > 0) {
                int prevlast = currlast;
            
                for(int& index : counts[word[i] - 'a']) {
                    if (index > currlast)  { 
                        currlast = index;
                        break;
                    }
                }
        
                if (currlast == prevlast) break;
            }   
            else break;
            
            if (i == word.length() - 1) res++;
        }

    }
    
    
    return res;
}