class Solution {
public:
    void solve(vector<vector<int>> &ans, int sum, vector<int> &temp, int index, vector<int> candidates, int target) {
        if(sum > target) {
            return;
        }
        if(index == candidates.size()) {
            if(sum == target) {
                ans.push_back(temp);
            }
            return;
        }
        temp.push_back(candidates[index]);
        solve(ans, sum + candidates[index], temp, index, candidates, target);
        temp.pop_back();
        solve(ans, sum, temp, index + 1, candidates, target);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(ans, 0, temp, 0, candidates, target);
        return ans;
    }
};