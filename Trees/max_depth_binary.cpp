struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 

// recursive implementation
int maxDepth(TreeNode* root) {
    if (root == nullptr) return 0;

    int maxLeft = maxDepth(root->left);         
    int maxRight = maxDepth(root->right);
    if (maxLeft > maxRight)
        return maxLeft+1;
    else
        return maxRight+1;
    
}

/* Related Topics

*/