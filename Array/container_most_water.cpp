#include <vector>
#include <iostream>

using namespace std;

int maxArea(vector<int>& height) {
    
    int max = 0;
    
    for(int i = 0; i  < height.size(); i++) {
        for(int j = i + 1; j < height.size(); j++) {
            int curmax = std::min(height[i], height[j]);
            int posmax = (j - i) *  curmax;
            if (posmax > max) {max = posmax; cout <<"curri: " << i << " currj: " << j << endl;}
        }    
    }
    
    return max;
    
    
}

int main() {
    vector<int> input{1,8,6,2,5,4,8,3,7};
    int result = maxArea(input);
    cout << "result: " << result;
}

