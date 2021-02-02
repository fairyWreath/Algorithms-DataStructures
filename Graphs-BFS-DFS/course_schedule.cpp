#include <vector>

using namespace std;

// basically check if a cycle exists using dfs

bool dfs(vector<vector<int>>& adj, vector<int>& visited, int start, vector<int>& currentVis) {
    
    visited[start] = 1;
    currentVis[start] = 1;
    
    for(auto& node : adj[start]) {
        if(visited[node] == 0 && !dfs(adj, visited, node, currentVis)) return false;
        if(currentVis[node] == 1) return false;
    }

    currentVis[start] = 0;
    
    return true;
} 

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> visited(numCourses, 0);
    vector<vector<int>> adj(numCourses);
    
    for(auto& preq : prerequisites) 
        adj[preq[1]].push_back(preq[0]);
    
    vector<int> currentVis(numCourses, 0);
    
    for(int i = 0; i < numCourses; i++) {
        if (!dfs(adj, visited, i, currentVis)) return false;
    }


    return true;
    
}

// DFS, BFS