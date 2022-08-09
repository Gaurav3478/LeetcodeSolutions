class Solution {
public:
    bool recurse(int idx, int n, vector<int> &nums, vector<int> &dp) {
        if(idx == n) {
            return true;
        }
        bool res = false;
        if(dp[idx] != -1) {
            return dp[idx];
        }
        if(idx < n-1 && nums[idx] == nums[idx + 1]) {
            res = res || recurse(idx + 2, n, nums, dp);
            if(idx < n-2 && nums[idx] == nums[idx + 2]) {
                res = res || recurse(idx + 3, n, nums, dp);
            }
        }
        if(idx + 2 < n && nums[idx + 2] - nums[idx + 1] == 1 && nums[idx + 1] - nums[idx] == 1) {
            res = res || recurse(idx + 3, n, nums, dp);
        }
        return dp[idx] = res;
    }
    
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return recurse(0, n, nums, dp);
    }
};