#include <vector>
#include <iostream>

using namespace std;



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


void inorder(TreeNode* root, vector<int>& arr) {
    if (root == nullptr) return;
    inorder(root->left, arr);
    arr.push_back(root->val);
    inorder(root->right, arr);
}

void makeBST(TreeNode* &root, int start, int end, vector<int>& sorted) {
    if (end < start) return;
    int mid = start + (end - start) / 2;
    
    root = new TreeNode(sorted[mid]);
    
    makeBST(root->left, start, mid-1, sorted);
    makeBST(root->right,mid+1, end, sorted);
}
    
TreeNode* balanceBST(TreeNode* root) {
    vector<int> sorted;
    inorder(root, sorted);
    
    TreeNode* res = nullptr;
    makeBST(res, 0, sorted.size() - 1, sorted);
    
    return res;
}