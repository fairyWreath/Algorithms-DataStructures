#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

bool wordPattern(string pattern, string s) {
    string current = "";
    vector<string> strings;
    
    for(auto& c : s) {
        if (c == ' ' && current != "") {
            strings.push_back(current);
            current = "";
        }    
        else current += c;
    }
    
    if (current != "") strings.push_back(current);
    
    if(strings.size() != pattern.size()) return false;
    
    unordered_map<string, char> hashmap;
    unordered_map<char, string> hashmap2;
    
    for(int i = 0; i < pattern.size(); i++) {
        if (hashmap.find(strings[i]) != hashmap.end()) {
            if (hashmap.find(strings[i])->second != pattern[i]) return false;
        }
        if (hashmap2.find(pattern[i]) != hashmap2.end())
            if (hashmap2.find(pattern[i])->second != strings[i]) return false;
        
        hashmap[strings[i]] = pattern[i];
        hashmap2[pattern[i]] = strings[i];
    }
    
    return true;
}

// hashtables, strings