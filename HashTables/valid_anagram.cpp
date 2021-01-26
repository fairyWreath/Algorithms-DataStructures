#include <string>
#include <vector>

using namespace std;


bool isAnagram(string s, string t) {
    
    // sort solution, O(nlogn)
    // sort(s.begin(), s.end());
    // sort(t.begin(), t.end());
    // return s == t;
    
    
    // "hash table" solution, O(n)
    vector<int> first(26, 0);
    vector<int> second(26, 0);
    
    for(char& c : s) {
        first[c - 'a']++;
    }
    
    for(char&c : t) {
        second[c - 'a']++;
    }
    
    return first == second;
}