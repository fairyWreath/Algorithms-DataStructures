#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

 int charToInt2(char c) {
        return static_cast<int>(c - 'A' + 1);
    }
    
int titleToNumber2(string s) {
    int result = 0;
    reverse(s.begin(), s.end());
    
    
    for(int i = 0; i < s.size(); i++) {
        result += (pow(26, i))*(charToInt(s[i]));
    }
    
    return result;
}

// better
 int charToInt(char c) {
    return static_cast<int>(c - 'A' + 1);
}
    
int titleToNumber(string s) {
    int result = 0;


    for(int i = s.size() - 1; i >= 0; i--) {
        result += (pow(26, s.size() -i - 1))*(charToInt(s[i]));
    }
    
    return result;
}