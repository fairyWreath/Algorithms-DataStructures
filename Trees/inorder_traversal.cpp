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


void inorder(vector<int>& result, TreeNode* root) {
    if (root == nullptr) return;
    
    inorder(result, root->left);

    // add current value
    result.push_back(root->val);
    
    inorder(result, root->right);
}    
    
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    
    if(root == nullptr) return result;
    
    inorder(result, root->left);
    result.push_back(root->val);
    inorder(result, root->right);
    
    return result;
}