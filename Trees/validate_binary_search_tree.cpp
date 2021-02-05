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

// validate by performing an inorder traversal
// one pointer based on array

bool validate(TreeNode* root, int*& last) {
    if(root == nullptr) return true;
    
    
    if (!validate(root->left, last)) return false;
    
    if(last && root->val <= *last) return false;
    if(!last) last =  new int();
    *last = root->val;
        
    if(!validate(root->right, last)) return false;
    
        return true;
}

void validate(TreeNode* root, vector<int>& tree) {
    if (!root) return;
    
    validate(root->left, tree);
    tree.push_back(root->val);
    validate(root->right, tree);
}

bool isValidBST(TreeNode* root) {
//         vector<int> tree;
//         validate(root, tree);
    
//         for(int i = 1; i < tree.size(); i++) {
//             if (tree[i-1] >= tree[i]) return false;     //BST needs value to be different
//         }
    
    int* num = nullptr;
    return validate(root, num);
}