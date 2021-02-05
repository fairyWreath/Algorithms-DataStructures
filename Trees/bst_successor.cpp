#include <vector>

using namespace std;

 
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// from ece 250 :)

TreeNode* minimumBST(TreeNode* node) {
    while(node->left != nullptr)
        node = node->left;
    return node;
}


TreeNode* bstSuccessor(TreeNode* node) {
    // if right is not empty, return minimum from right
    if (node->right != nullptr)
        return minimumBST(node->right);

    // if right is empty, check that current node is a right child or not;
    // if it is a left child simply return the parent
    // if it is a right child , go up the tree and repeat    
    TreeNode* temp = node->parent;
    while(temp != nullptr && node == temp->right) {
        node = temp;
        temp = temp->parent;
    }
    return temp;
}