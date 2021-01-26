#include <string>
#include <algorithm>

using namespace std;

string remove(string s)
{
    string result = "";
    for (char& c : s)
    {
        if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
            result += c;
    }

    return result;
}

bool isPalindrome(string s)
{
    if (s == "") return true;
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    s = remove(s);
    int frontIndex = 0;
    int backIndex = s.length() - 1;

    string front = "";

    for (frontIndex; frontIndex < s.length() / 2; frontIndex++)
    {
        front += s[frontIndex];
    }

    string back = "";
    int backstop = 0;

    if (s.length() % 2 != 0)
        backstop = s.length() / 2;
    else
        backstop = s.length() / 2 - 1;

    for (backIndex; backIndex > backstop; backIndex--)
    {
        back += s[backIndex];
    }

    if (front == back)
        return true;
    else
        return false;
    

}