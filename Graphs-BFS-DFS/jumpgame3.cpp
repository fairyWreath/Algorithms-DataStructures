#include <vector>

using namespace std;

bool dfs(vector<int>& arr, vector<int>& visited, int start) {
    if (arr[start] == 0) return true;
    if (visited[start] == 1) return false;      // cycle detected
    visited[start] = 1;
    
    bool first = false, second = false;
    
    if (start - arr[start] >= 0) {
        first = dfs(arr, visited, start - arr[start]);
    }
    
    if (start + arr[start] < arr.size()) {
        second = dfs(arr, visited, start + arr[start]);
    }
    
    visited[start] = 0;             // backtrack
    return first || second;
}

bool canReach(vector<int>& arr, int start) {
    vector<int> visited(arr.size(), 0);
    
    return dfs(arr, visited, start);
}

//dfs, bfs