#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// do a bfs / rootfirst searchw while keeping track of the current level
void order(TreeNode* root, vector<vector<int>>&res, int currlvl) {
    if (root == nullptr) return;
    if (currlvl > res.size()) res.push_back(vector<int>());
    
    res[currlvl - 1].push_back(root->val);
    order(root->left, res, currlvl+1);
    order(root->right, res, currlvl+1);
}
    
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    order(root, res, 1);
    return res;
}
    