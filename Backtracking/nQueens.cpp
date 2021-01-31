#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

void solvePart(vector<int>& current, vector<vector<int>>& result, int n)  {
    if (current.size() == n)  {
        result.push_back(current);
        return;
    }
    
    for(int i = 0; i < n; i++) {
        // if new or not found add to current permutation(different row)
        if (find(current.begin(), current.end(), i) == current.end()) {
            // check diagonally
            bool diag = false;
            for(int j = 0; j < current.size(); j++) {
                if (abs(i - current[j]) == current.size() - j) {
                    diag = true;
                    break;
                }
            }
            
            if (!diag) {
                current.push_back(i);
                solvePart(current, result, n);
                current.pop_back();
            }
            
        }
    }

}


vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> final;
    vector<vector<int>> result;         // save as column array
    vector<int> current;

    solvePart(current, result, n);

    // convert to string
    for(auto& r : result) {
        vector<string> board;
        for(auto& col : r) {
            string row = "";
            for(int i = 0; i < n; i++) {
                if (i == col) row += "Q";
                else row += ".";
            }
            board.push_back(row);
        }
        final.push_back(board);
    }
    
    return final;
}

int main() {
    solveNQueens(4);
}

// backtracking