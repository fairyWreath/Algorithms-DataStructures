#include <vector>
#include <string>
#include <iostream>

using namespace std;


void findCombinations(vector<string>& res, string& current, int start, int target, vector<string> charpool) {
    if (current.length() == target) {
        res.push_back(current);
        return;
    }
    
    for(int i = start; i < charpool.size(); i++) {
        
        // pick from current pool
        for(int j = 0; j < charpool[i].size(); j++) {
            current += charpool[i][j];
            findCombinations(res, current, i + 1, target, charpool);
            current = current.substr(0, current.length()-1);
        }
    }
    
}

vector<string> letterCombinations(string digits) {
    vector<vector<char>> charpool;
    
    vector<string> chars = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    // you do not have to create a pool
    vector<string> pool;
    
    for(char& c : digits) {
        pool.push_back(chars[static_cast<int>(c - '0') - 2]);
    }
    
    // create from scratch
//         for(char& c : digits) {
//             charpool.push_back(vector<char>());
//             int index = charpool.size() - 1;
        
//             int start = (static_cast<int>(c - '0') - 2);
        
//             int toadd = 3;
//             if (start == 5 || start == 7) toadd = 4;
        
//             if(start < 6)
//                 start *= 3;
//             else if (start >= 6)
//                 start = (start - 1) * 3 + 4;

    
//             for(int i = start; i < start + toadd; i++) {
//              charpool[index].push_back(static_cast<char>(i + 'a'));
//             }
//         }
    
    int num = digits.length();
    string current;
    vector<string> res;
    if (num == 0) return res;
    
    findCombinations(res, current, 0, num, pool);    
    return res;
}