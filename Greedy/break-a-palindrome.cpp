#include <string>

using namespace std;

string breakPalindrome(string palindrome) {
    if (palindrome.length() == 1) return "";
    
    string res = palindrome;
    bool nota = false;
    
    for(int i = 0; i < palindrome.length() / 2; i++) {
        if (palindrome[i] != 'a') {
            res[i] = 'a';
            nota = true;
            break;
        }
    }
    
    if (!nota) res[res.length() - 1] = 'b';
    return res;
}

// greedy algos, string