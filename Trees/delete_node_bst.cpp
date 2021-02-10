struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


TreeNode* minimumBST(TreeNode* node) {
    while(node->left != nullptr) {
        node = node->left;
    }
    return node;
}

TreeNode* deleteBST(TreeNode* root, int key) {
    if(!root) return nullptr;
    
    if (root->val == key) {
        if(!root->left) return root->right;
        if (!root->right) return root->left;
        
        // if two children exists
        TreeNode* successor = minimumBST(root->right);
        root->val = successor->val;     // copy the data
        
        root->right = deleteBST(root->right, root->val);
    }
    
    else if (key < root->val) root->left = deleteBST(root->left, key);
    else root->right = deleteBST(root->right, key);
    
    return root;
}

TreeNode* deleteNode(TreeNode* root, int key) {
    root = deleteBST(root, key);
    return root;
}

// trees, bst