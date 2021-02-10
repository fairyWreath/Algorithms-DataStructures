#include <vector>
#include <iostream>

using namespace std;

string simplifyPath(string path) {
    vector<string> stack;
    
    string current = "";    
    for(int i = 0; i < path.length(); i++) {
        if (path[i] == '/' || i == path.length() - 1) {
            if (path[i] != '/')  current += path[i];        // for final case if does not end with /
            
            if (current.length() > 0) {
                if (current == "..") { 
                    if (stack.size() > 0)
                        stack.pop_back();
                }
                else if (current != ".")
                    stack.push_back(current);
                current = "";
            }
            continue;
        }

        current += path[i];
    }

    string final = "";
    
    for(string& dir : stack) {
        final += "/";
        final += dir;
    }
     if (stack.size() == 0) final += "/";
    
    return final;
}


int main() {
    string input = "/.../....";

    string res = simplifyPath(input);
    cout << res;
}

// string, stack, arrays