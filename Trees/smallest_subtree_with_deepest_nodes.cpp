 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* lowest(TreeNode* root, int& depth) {
    if (!root) return nullptr;
    
    depth++;
    int depthleft = depth;
    int depthright = depth;
    
    TreeNode* lowestLeft = lowest(root->left,  depthleft);
    TreeNode* lowestRight = lowest(root->right, depthright);
    
    if(!lowestLeft && !lowestRight) return root;
    
    if(depthleft > depthright) {
            depth = depthleft;
        return lowestLeft;
    }
    else if (depthleft == depthright) {
        depth = depthleft;
        return root;
    }
    else {
            depth = depthright;
        return lowestRight;
    }
    
}    

TreeNode* subtreeWithAllDeepest(TreeNode* root) {
    int start = 0;
    return lowest(root, start);
}