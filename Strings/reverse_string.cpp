#include <iostream>
#include <vector>

using namespace std;

void reverseString(vector<char>& s) {
    vector<char>::iterator front = s.begin();
    vector<char>::reverse_iterator back = s.rbegin();
    
    char temp;
    
    for (int i = 0; i < s.size() / 2; i++) 
    {
        temp = *front;
        *front = *back;
        *back = temp;
        front++;
        back++;
    }
    
}