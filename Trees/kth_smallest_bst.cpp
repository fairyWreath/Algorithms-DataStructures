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

void inorder(TreeNode* root, vector<int>& res) {
    if (root == nullptr) return;
    inorder(root->left, res);
    res.push_back(root->val);
    inorder(root->right, res);
}


int kthSmallest(TreeNode* root, int k) {
    vector<int> res;
    inorder(root, res);
    return res[k-1];
}