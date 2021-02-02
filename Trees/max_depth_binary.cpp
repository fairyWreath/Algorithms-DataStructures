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
 

// recursive implementation
int maxDepth(TreeNode* root) {
    if (root == nullptr) return 0;

    int maxLeft = maxDepth(root->left);         
    int maxRight = maxDepth(root->right);

    // adding is done here
    if (maxLeft > maxRight)
        return maxLeft+1;
    else
        return maxRight+1;
    
}

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


int maxDepthN(Node* root) {
    if (root == nullptr) return 0;
    
    int max = 0;
    
    for(Node*& node : root->children) {
        int currmax = maxDepthN(node) ;
        if(currmax > max) max = currmax;
    }
    
    return max + 1;
}

/* Related Topics
trees
*/