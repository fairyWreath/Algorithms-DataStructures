#include <vector>
#include <string>
#include <iostream>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if (strs.size() == 0) return "";
    
    char current;
    bool init = false;
    
    string res = "";
    int i = 0;
    
    bool diff = false;
    
    while(true) {
        for (auto& s : strs) {
            if (i > s.length() - 1 || s == "") {
                diff = true;
                break;
            }
            if (!init) {
                current = s[i];
                init = true;
            }
            else {
                if (s[i] != current) {
                    diff = true;
                    break;
                } 
            }
        }
        
        if (diff) break;
        res += current;
        i++;
        init = false;
    }
    
    
    return res;
}

int main() {

    vector<string> strs{""};
    string res = longestCommonPrefix(strs);

    cout << res;
    return 0;
}