class Solution {
public:
    void solve(vector<vector<int>> &ans, vector<int> &temp, int index, int sum, vector<int> candidates, int target) {
        if(index == candidates.size()) {
            if(sum == target) {
                ans.push_back(temp);
            }
            return;
        }
        temp.push_back(candidates[index]);
        if(sum + candidates[index] <= target) {
            solve(ans, temp, index + 1, sum + candidates[index], candidates, target);
        }
        int j = index;
        while(index < candidates.size() && candidates[index] == candidates[j]) {
            index++;
        }
        index--;
        temp.pop_back();
        solve(ans, temp, index + 1, sum, candidates, target);
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        solve(ans, temp, 0, 0, candidates, target);
        return ans;
    }
};