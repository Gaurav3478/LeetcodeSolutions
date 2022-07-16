class Solution {
public:
    int solve(int i, int currSum, int target, vector<vector<int>> &dp, vector<int> &nums) {
        if(i == nums.size()) {
            if(currSum == target) {
                return 1;
            }
            else {
                return 0;
            }
        }
        if(dp[i][currSum + 1000] != -1) {
            return dp[i][currSum + 1000];
        }
        int val = 0;
        val = solve(i + 1, currSum + nums[i], target, dp, nums);
        val += solve(i + 1, currSum - nums[i], target, dp, nums);
        return dp[i][currSum + 1000] = val;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int currSum = 0;
        int idx = 0;
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++) {
            sum += nums[i];
        }
        vector<vector<int>> dp(n, vector<int>(2001, -1));
        return solve(idx, currSum, target, dp, nums);
    }
};