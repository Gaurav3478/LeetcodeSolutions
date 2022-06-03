class Solution {
public:
    void solve(vector<vector<int>> &ans, vector<int> &temp, int index, int curr_sum, vector<int> &candidates, int target, int n) {
        if(index >= n || curr_sum > target) {
            return;
        }
        if(curr_sum == target) {
            ans.push_back(temp);
            return;
        }
        //include 
        curr_sum += candidates[index];
        temp.push_back(candidates[index]);
        solve(ans, temp, index, curr_sum, candidates, target, n);
        curr_sum -= candidates[index];
        temp.pop_back();
        solve(ans, temp, index + 1, curr_sum, candidates, target, n);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        //we will either include or not include
        vector<vector<int>> ans;
        int n = candidates.size();
        vector<int> temp;
        solve(ans, temp, 0, 0, candidates, target, n);
        //ans temp index curr_sum candidates required_sum array_size
        return ans;    
    }
};