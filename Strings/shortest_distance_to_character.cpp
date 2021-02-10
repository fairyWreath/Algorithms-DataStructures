#include <vector>
#include <string>

using namespace std;

// store location and update
vector<int> shortestToChar(string s, char c) {
    vector<int> res;
    
    vector<int> locations;
    for(int i = 0; i < s.size(); i++) {
        if (s[i] == c) locations.push_back(i);
    }
    
    int current = 0;
    for(int i = 0; i < s.size(); i++) {
        if (current < locations.size() - 1) {
            if (abs(i - locations[current]) > abs(i-locations[current + 1]))
                current++;
        }
        
        res.push_back(abs(i - locations[current]));
    }
    
    return res;
}

// construct based on distanced found
vector<int> shortestToChar2(string s, char c) {
    vector<int> res(s.size(), INT_MAX);

    for(int i = 0; i < s.size(); i++) {
        if (s[i] != c) continue;
        
        res[i] = 0;

        for(int j = 0; j < i; j++) {
            
        }

        for(int j = i; j < s.size(); j++) {

        }
    }
    
    
    return res;
}