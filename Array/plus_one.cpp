#include <vector>

using namespace std;

vector<int> plusOne(vector<int>& digits) {
    vector<int> res;
    bool add = true;
    bool prev9 = false;
    
    for(int i = digits.size() - 1; i >= 0; i--) {
        int num = digits[i];
        if(add) {
            num = num + 1;
            if (num == 10) {
                res.push_back(0);
            }
            else {
                res.push_back(num);
                add = false;
            }
        }
        else {
            res.push_back(num);
        }
    }
    
    if (add) res.push_back(1);
    
    
    reverse(res.begin(), res.end());
    return res;
}