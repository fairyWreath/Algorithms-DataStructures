#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


vector<int> rightSideView(TreeNode* root) {
    vector<int> result;
    
    // level order traversal with BFS
    queue<TreeNode*> q;
    if (root) q.push(root);
    
    while(!q.empty()) {
        int currlen = q.size();
        for(int i = 0; i < currlen; i++) {
            TreeNode* curr = q.front();
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
            if (i == currlen - 1) result.push_back(curr->val);
            q.pop();
        }
    }
    
    return result;
}

// bfs, dfs , trees