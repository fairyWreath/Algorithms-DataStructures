#include <set>
#include <vector>

using namespace std;



void dfs(vector<vector<int>>& adj, vector<set<int>>& reaches, vector<int>& visited, int start) {
    visited[start] = true;
    
    for(auto& node : adj[start]) {
        reaches[start].insert(node);
        if (visited[node] == 0) dfs(adj, reaches, visited, node);
        
        // insert all reachable nodes from the current reachable node
        reaches[start].insert(reaches[node].begin(), reaches[node].end());
    }
    
}

vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
    vector<bool> res;
            
    vector<vector<int>> adj(n);
    for(auto& preq : prerequisites) {
        adj[preq[0]].push_back(preq[1]);
    }
    
    vector<set<int>> isReachable(n);        // use a set to track reachable nodes
    vector<int> visited(n, 0);
    
    for(int i = 0; i < n; i++) {
        if (visited[i] == 0)
            dfs(adj, isReachable, visited, i);
    }
    
    for(auto& quer : queries) {
        if (isReachable[quer[0]].find(quer[1]) != isReachable[quer[0]].end())
            res.push_back(true);
        else res.push_back(false);
    }
    
    
    return res;
}


// bfs, dfs