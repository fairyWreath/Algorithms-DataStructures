#include <iostream>
#include <vector>

using namespace std;

char getPair(char in) {
    switch(in) {
        case '(':
            return ')';
        case '[':
            return ']';
        case '{':
            return '}';
        default:
            return ' ';
    }
}
    
    
bool isValid(string s) {
    vector<char> lastChar;

    for(auto& c : s) {
        if (c == '(' || c == '[' || c == '{')
            lastChar.push_back(c);
        else {
            if (lastChar.size() == 0) return false;
                if (c != getPair(lastChar.back()))
                    return false;
            lastChar.pop_back();
        }
    }
    
    if (lastChar.size() > 0) return false;
    
    return true;
}