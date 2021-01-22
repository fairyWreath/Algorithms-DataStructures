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

TreeNode* getbst(vector<int>& nums, int start, int end) {
    if (start > end) return nullptr;
    
    int mid = (start+end)/2;
    TreeNode* node = new TreeNode(nums[mid]);
    
    node->left = getbst(nums, start, mid - 1);
    node->right = getbst(nums, mid + 1, end);
    
    return node;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    TreeNode* root = getbst(nums, 0, nums.size() - 1);
    
    return root;
}