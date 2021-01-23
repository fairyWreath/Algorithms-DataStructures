#include <vector>
#include <queue>

using namespace std;

int kthSmallest(vector<vector<int>>& matrix, int k) {
    
    // use a min heap
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    for(auto& col : matrix) {
        for(int& ele : col) {
            minHeap.push(ele);
        }
    }
    
    for(int i = 0; i < k - 1; i++) {
        minHeap.pop();    
    }
    
    return minHeap.top();
}

/* better solution memorywise from 
typedef pair<int,pair<int,int>> T;
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<T,vector<T>,greater<T>> pq;
        int n = matrix[0].size();
        for(int i=0;i<n;i++)
            pq.push({matrix[i][0],{i,0}});
            
        int ele;
        while(k--)
        {
            T temp = pq.top();
            pq.pop();
            ele = temp.first;
            int r = temp.second.first;
            int c = temp.second.second;
            if(++c < n)
                pq.push({matrix[r][c],{r,c}});
        }
        return ele;
    }
};
*/