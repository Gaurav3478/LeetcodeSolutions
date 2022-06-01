class Solution {
public:
    void solve(vector<vector<int>> &ans, int index, vector<int> &temp, vector<int> nums, int n) {
        if(index == n) {
            ans.push_back(temp);
            return;
        }
        //we take that index
        solve(ans, index+1, temp, nums, n);
        temp.push_back(nums[index]);
        solve(ans, index+1, temp, nums, n);
        temp.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        //in general, we'll take then skip then take then skip
        vector<vector<int>> ans;
        vector<int> temp;
        int n = nums.size();
        solve(ans, 0, temp, nums, n);
        return ans;
    }
};