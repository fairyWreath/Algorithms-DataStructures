#include <vector>
#include <string>
#include <algorithm>


/* trees, bfs, dfs*/ 
using namespace std;
 
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* PATH SUM 3 */
 // bruteforce count from each node, O(n^2)
void dfs(TreeNode* root, int sum, int& count) {
    if (!root) return;

    // traverse whole tree from current node
    traverse(root, 0, sum, count);
    
    dfs(root->left, sum, count);
    dfs(root->right, sum, count);
}


void traverse(TreeNode* root, int currsum, int sum, int& count) {
    if (!root) return;
    
    currsum += root->val;
    if (currsum == sum) count++;
    
    traverse(root->left, currsum, sum, count);
    traverse(root->right, currsum, sum, count);
}


int pathSum3(TreeNode* root, int sum) {
    int count = 0;
    dfs(root, sum, count);
    
    return count;
}



/* PATH SUM 2 */
// backtracking approach
void backtrack(TreeNode* root, vector<vector<int>>& res, vector<int>& path, int targetSum, int currentSum) {
    if (!root) return;
    
    path.push_back(root->val);
    currentSum += root->val;
    if (!root->left && !root->right && currentSum == targetSum) res.push_back(path);
    
    backtrack(root->left, res, path, targetSum, currentSum);
    backtrack(root->right, res, path, targetSum, currentSum);
    path.pop_back();
}

vector<vector<int>> pathSum2(TreeNode* root, int targetSum) {
    vector<vector<int>> res;
    vector<int> curr;
    
    backtrack(root, res, curr, targetSum, 0);
    
    
    return res;
}


/* SUM ROOT TO LEAF NUMBERS */
void traverse(TreeNode* root, string& current, int& sum) {
    if(!root) return;
    
    current += to_string(root->val);
    
    if(!root->left && !root->right) sum += stoi(current);
    
    traverse(root->left, current, sum);
    traverse(root->right, current, sum);
    
    current = current.substr(0, current.length() - to_string(root->val).length());
}

int sumNumbers(TreeNode* root) {
    int sum = 0;
    string current = "";
    traverse(root, current, sum);
    
    return sum;
}


// smallest string from leaf
void traverse(TreeNode* root, string& least, string& current) {
    if (!root) return;
    
    current += static_cast<char>('a' + root->val);
    
    if(!root->left && !root->right) {
        string copy = current;
        reverse(copy.begin(), copy.end());
        
        if(least == "" || copy < least)
            least = copy;
    }
    
    traverse(root->left, least, current);
    traverse(root->right, least, current);
    
    current = current.substr(0, current.length() - 1);      // guaranteed to be 1 char from each root
}

string smallestFromLeaf(TreeNode* root) {
    string least = "";
    string current = "";
    traverse(root, least, current);
    
    return least;
}