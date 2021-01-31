#include <vector>

using namespace std;


// because we have a bst simply do an inorder traversal of the tree

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
    void order(TreeNode* root, vector<int>& res, int level) {
        if(!root) return;
        
        // do bfs, newest will always be the currently deepest one
        if(res.size() < level+ 1) res.push_back(root->val);
        else if (root->val > res[level]) res[level] = root->val;
      
        
        order(root->left, res, level + 1);
        order(root->right, res, level + 1);
    }
    
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        order(root, res, 0);
        
        return res;
    }
    
    
};