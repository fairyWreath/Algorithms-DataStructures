#include <vector>

using namespace std;

    // graph coloring with two colors and DFS
    // unvisited nodes will be colored with -1
    
bool color(vector<vector<int>>& adj, vector<int>& colors, vector<int>& current, int tocolor)     {
    colors[current.back()] = tocolor;
    
    for(auto& node : adj[current.back()]) {
        if (colors[node] == colors[current.back()])
            return false;
        current.push_back(node);
        if (colors[current.back()] == -1 && !color(adj, colors, current, tocolor^1))        // if not yet colored traverse again
            return false;
        current.pop_back();
    }
    return true;
}


bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
    vector<vector<int>> adj(N + 1);             // from 1 to N
    vector<int> colors(N+1, -1);
    
    for(auto& v : dislikes) {
        adj[v[0]].push_back(v[1]);
        adj[v[1]].push_back(v[0]);
    }
    vector<int> current;
        
    bool res = true;
    
    for(int i = 1; i <= N; i++) {
        current.push_back(i);
        if (colors[i] == -1)
            res = color(adj, colors, current, 0);
        current.pop_back();
    }
    
    return res;
}


// possible bipartition given adj graph
bool color2(vector<vector<int>>& adj, vector<int>& colors, vector<int>& current, int tocolor)     {
    colors[current.back()] = tocolor;

    for(auto& node : adj[current.back()]) {
        if (colors[node] == colors[current.back()])
            return false;
        current.push_back(node);
        if (colors[current.back()] == -1 && !color(adj, colors, current, tocolor^1))
            return false;
        current.pop_back();
    }
    return true;
}
    
    
bool isBipartite(vector<vector<int>>& graph) {
    vector<int> current;
    vector<int> colors(graph.size(), -1);    

    for(int i = 0; i < graph.size(); i++) {
        current.push_back(i);
        if (colors[i] == -1)
            if(!color2(graph, colors, current, 0)) return false;
        current.pop_back();
    }

    return true;
}

// DFS, backtracking, BFS