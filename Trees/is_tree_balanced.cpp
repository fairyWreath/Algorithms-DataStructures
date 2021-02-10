 #include <algorithm>
 
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// check height while passing up error
int checkBalance(TreeNode* root) {
    if(root == nullptr) return -1;          // -1 to nulify +! called previously
    
    // pass up errror within one function
    int left = checkBalance(root->left);
    if(left == INT_MIN) return INT_MIN;
    int right = checkBalance(root->right);
    if(right == INT_MIN) return INT_MIN;
    
    if(abs(left-right) > 1) return INT_MIN;
    return std::max(left, right) + 1;
}


bool isBalanced(TreeNode* root) {
    return checkBalance(root) != INT_MIN;       // INT_MIN is the error code
}

// trees