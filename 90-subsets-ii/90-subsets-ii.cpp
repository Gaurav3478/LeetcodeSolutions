class Solution {
public:
    void solve(int ind, vector<int> &temp, vector<int> &nums, set<vector<int>> &ans, int n) {
        if(ind == n) {
            ans.insert(temp);
            return;
        }
        vector<int> x;
        x = temp;
        x.push_back(nums[ind]);
        solve(ind + 1, x, nums, ans, n);
        solve(ind + 1, temp, nums, ans, n);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> ans;
        int n = nums.size();
        vector<int> temp;
        solve(0, temp, nums, ans, n);
        vector<vector<int>> v;
        for(auto i: ans) {
            v.push_back(i);
        }
        return v;
    }
};