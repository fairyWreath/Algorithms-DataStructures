#include <vector>

using namespace std;

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

class Solution {
public:

    // preorder traversal but save to array by tracking with levels, BFS done here
    void order(vector<vector<int>>& res, int level, Node* root) {
        if (root == nullptr) return;
        
        if (res.size() < level + 1) res.push_back(vector<int>());
        res[level].push_back(root->val);
        
        for(auto& child : root->children) {
            order(res, level+1, child);    
        }
        
        
    }
    
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        order(res, 0, root);
        
        return res;
    }
};


// trees