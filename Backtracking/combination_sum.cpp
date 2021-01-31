#include <vector>
#include <algorithm>

using namespace std;

// from leetcode 


class Solution {
public:
    
    int nTarget;
    
    void findC(vector<int>& candidates, vector<vector<int>>& result, vector<int>& current, int total, int start) {
        if (total >= nTarget) {
            if (total == nTarget) result.push_back(current);
            return;
        } 
        
        for(int i = start; i < candidates.size(); i++) {
            current.push_back(candidates[i]);
            findC(candidates, result, current, total + candidates[i], i);
            current.pop_back();
        }
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> current;
        vector<vector<int>> result;
        nTarget = target;
        
        findC(candidates, result, current, 0, 0);
        
        return result;
    }
};


class Solution2 {
public:
    void findC(vector<int>& candidates, vector<vector<int>>& result, vector<int>& current, int target, int total, int start) {
        if (total >= target) {
            if (total == target) result.push_back(current);
            return;
        } 
        
        for(int i = start; i < candidates.size(); i++) {
            /* question is actually bad:(
            if a similar digit apperas twice we cannot use it for
            two different cases, hence why we sort and use continue here
            */
           if (i > start && candidates[i - 1] == candidates[i]) continue;
            
            current.push_back(candidates[i]);
            findC(candidates, result, current, target, total + candidates[i], i + 1);
            current.pop_back();;
        }
    }
    
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> current;
        vector<vector<int>> result;
        sort(candidates.begin(), candidates.end());
        
        
        findC(candidates, result, current, target, 0, 0);
        
        return result;
    }
};

// backtracking, dfs


class Solution3{
public:
        void findC(vector<vector<int>>& result, vector<int>& current, int maxSize, int target, int total, int start) {
        if (current.size() > maxSize) return;    
            
        if (total >= target) {
            if (total == target && current.size() == maxSize) result.push_back(current);
            return;
        } 
        
        // limit through settings start pos; if it goes over start pos that combination is  already handled
        for(int i = start; i <= 9; i++) {
            current.push_back(i);
            findC(result, current, maxSize, target, total + i, i + 1);
            current.pop_back();;
        }
    }
    
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> current;
        
        findC(res, current, k, n, 0, 1);
        return res;
    }
};