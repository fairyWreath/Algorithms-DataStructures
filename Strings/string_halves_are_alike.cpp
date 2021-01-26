 #include <string>
 
 
 using namespace std;

 bool isVowel(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' 
           || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            return true;
        return false;
    }    
    
bool halvesAreAlike(string s) {
    string first = s.substr(0, s.length() / 2);
    string second = s.substr(s.length()/2, s.length()/2);
    
    int fcount = 0, scount = 0;
    
    for (auto& c : first) {
        if (isVowel(c))
            fcount++;
    }
    
    for(auto& c : second) {
        if (isVowel(c))
            scount++;
    }
    
    return fcount == scount;
}