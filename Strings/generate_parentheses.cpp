#include <vector>
#include <string>
#include <iostream>

using namespace std;

void permute(int n, int currOpen, vector<string>& parPermutations, string permutation) {
    if (permutation.size() == n) {
        parPermutations.push_back(permutation);
        cout << "added perm: " << permutation << endl;
        return;
    }
    
    if (currOpen < n - permutation.size()) {
        permute(n, currOpen + 1, parPermutations, permutation + '(');
    }
    // backtrack possibility 
    if (currOpen > 0) {
        permute(n, currOpen - 1, parPermutations, permutation + ')');
    }
}
    
vector<string> generateParenthesis(int n) {
    vector<string> permutes;
    permute(n * 2, 0, permutes, "");
    
    return permutes;
}


int main() {
    vector<string> permutes;
    string curr = "";
    int op = 0;
    permute(6, op, permutes, curr);

    cout << permutes.size();

}

//related topics: string, backtracking