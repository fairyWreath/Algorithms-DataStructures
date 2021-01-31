#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> g;
    
    // simple backtrack DFS
    void findPath(vector<vector<int>>& result, vector<int>& current, int source) {
        if (current.back() == g.size() - 1) {
            result.push_back(current);
            return;
        }
        
        for(int& targ : g[source]) {
            current.push_back(targ);
            findPath(result, current, targ);
            current.pop_back();
        }
        
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        vector<int> current;
        g = graph;
        
        current.push_back(0);
        findPath(result, current, 0);
        
        return result;
    }
};

// backtracking