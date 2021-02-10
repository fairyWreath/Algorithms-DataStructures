#include <vector>
#include <queue>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    // bfs/level order traversal + spice
    Node* connect(Node* root) {
        
        // bfs
        queue<Node*> tovisit;
        if(root) tovisit.push(root);
        
        while(!tovisit.empty()) {
            int currlen = tovisit.size();
            for(int i = 0; i < currlen; i++) {
                Node* front = tovisit.front();
                tovisit.pop();
                if(i < currlen - 1)
                    front->next = tovisit.front();
                else
                    front->next = nullptr;
                
                if(front->left) tovisit.push(front->left);
                if(front->right) tovisit.push(front->right);
            }
        }
        
        return root;
    }
};