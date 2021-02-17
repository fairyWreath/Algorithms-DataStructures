#include <vector>
#include <string>
#include <algorithm>
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

// level order bst + indexing
int widthOfBinaryTree(TreeNode* root) {
    
    typedef pair<TreeNode*, unsigned long long> PAIR;
    int res = 0;
    queue<PAIR> q;
    
    if(!root) return res;
    
    q.push(PAIR(root, 1));
    
    
    while(!q.empty()) {
        int currsize = q.size();
        unsigned long long currmin = 0;
        unsigned long long currmax = 0;
        for(int i = 0; i < currsize; i++) {
            PAIR curr = q.front();
            q.pop();
            
            if (i == 0) currmin = curr.second;
            if (i == currsize - 1) currmax = curr.second;
            
            // indexing done here
            if(curr.first->left) q.push(PAIR(curr.first->left, curr.second * 2));
            if(curr.first->right) q.push(PAIR(curr.first->right, curr.second * 2 + 1));
        }
        
        if(currmax - currmin > res) res = currmax - currmin;
    }
    
    
    return res + 1;
}