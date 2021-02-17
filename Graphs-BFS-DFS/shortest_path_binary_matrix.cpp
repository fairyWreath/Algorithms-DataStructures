#include <vector>
#include <queue>

using namespace std;

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    typedef pair<int, int> PAIR;

    int N = grid.size() - 1;
    int count = 0;
    queue<PAIR> q;
    
    // first square case
    if(grid[0][0] != 0) return -1;
    q.push(PAIR(0, 0));
    grid[0][0] = 1;
    
    // directional vectors
    vector<int> dx{-1, 1, 0, 0, -1, -1, 1, 1};
    vector<int> dy{0, 0, -1, 1, -1, 1, -1, 1};
    
    while(!q.empty()) {
        int currlen = q.size();
        count++;
        for(int i = 0; i < currlen; i++) {
            PAIR curr = q.front();
            q.pop();
            
            if (curr == PAIR(N, N)) return count;

            for(int i = 0; i < 8; i++) {
                PAIR next(dx[i] + curr.first, dy[i] + curr.second);
                if (next.first >= 0 && next.second >= 0 && next.first < N + 1 &&
                    next.second < N + 1 && grid[next.first][next.second] == 0)  {
                    grid[next.first][next.second] = 1;
                    q.push(next);
                }
            }
        }
    }
    
    return -1;
}