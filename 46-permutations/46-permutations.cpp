//this will be the solution using extra space

class Solution {
public:
    void solve(vector<vector<int>> &ans, vector<int> nums, vector<int> &ds, vector<int> temp, int n) {
        if(ds.size() == n) {
            ans.push_back(ds);
            return;
        }
        for(int i = 0; i<n; i++) {
            if(!temp[i]) {
                temp[i] = 1;
                ds.push_back(nums[i]);
                solve(ans, nums, ds, temp, n);
                temp[i] = 0;
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        int n = nums.size();
        vector<int> temp(n);
        // for(int i = 0; i<temp.size(); i++) {
        //     temp[i] = 0;
        // }
        solve(ans, nums, ds, temp, n);
        return ans;
    }
};