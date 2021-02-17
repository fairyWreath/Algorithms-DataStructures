#include <string>
#include <iostream>


using namespace std;

bool validPalindrome(string s) {
    int front = 0;
    int back = s.size() - 1;
    
    bool found = false;
    
    while(front < back) {
        if (s[front] != s[back]) {
            if (!found) {
                if (s[front + 1] == s[back]) front++;
                else if (s[back-1] == s[front]) back--;
                
                cout << "skiiped one \n";
                found = true;
            }
            else {
                cout << s[front] << " " << front << " " << s[back] << back << endl;
                return false;
            }
        }
        
        front++;
        back--;
    }
    
    
    return true;
}

int main() {
    
    string s = "aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga";
    cout << s.size() << endl;
    
    cout << validPalindrome(s);
}


