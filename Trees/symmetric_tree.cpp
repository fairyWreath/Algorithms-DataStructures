#include <iostream>
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
    
    bool result;
    void traverse(TreeNode* root1, TreeNode* root2) {
        
        if (root1 == nullptr && root2 == nullptr) return;
        if (root1 == nullptr && root2 != nullptr) {
            result = false;
            return;
        }
        if (root2 == nullptr && root1 != nullptr) {
            result = false;
            return;
        }
        
        if(result) traverse(root1->left, root2->right);
        if (root1->val != root2->val) result = false;
        if (result) traverse(root1->right, root2->left);
    }
    
    bool isSymmetric(TreeNode* root) {    
        if (root == nullptr) return true;
        
        result = true;
        traverse(root->left, root->right);
        return result;
    }
    
};
