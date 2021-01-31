 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool hasSum(TreeNode* root, int targetSum, int sum) {
    if (root == nullptr) return false;
    
    sum += root->val;
    if (root->left == nullptr && root->right == nullptr && sum == targetSum) return true;
    
    bool left = hasSum(root->left, targetSum, sum);
    bool right = hasSum(root->right, targetSum, sum);

    if(left || right) return true; 
    return false;
}


bool hasPathSum(TreeNode* root, int targetSum) {
    return hasSum(root, targetSum, 0);
}

// trees, DFS