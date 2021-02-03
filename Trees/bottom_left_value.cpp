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

int findBottomLeftValue(TreeNode* root) {
    // simple BFS, DFS is much faster
    int res;
    queue<TreeNode*> q;
    q.push(root);
        
    while(!q.empty()) {
        int currlen = q.size();
        for(int i = 0; i < currlen; i++) {
            
            TreeNode* curr = q.front();
            if (i == 0) res = curr->val;
            q.pop();
            
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
    }
    
    
    return res;
}


// bfs, dfs tree