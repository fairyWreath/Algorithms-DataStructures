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


class Solution {
public:
      void zigzag(TreeNode* root, vector<vector<int>>& res, int level, bool toright) {
        if (root == nullptr) return;
        if (res.size() < level + 1) res.push_back(vector<int>());
        res[level].push_back(root->val);
        
        if(toright) {
            zigzag(root->left, res, level+1, !toright);
            zigzag(root->right, res, level+1, !toright);
        }
        else {
            zigzag(root->right, res, level+1, !toright);
            zigzag(root->left, res, level+1, !toright);
        }
        
    }
    
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        zigzag(root, result, 0, false);
        
        return result;
    }
    
};