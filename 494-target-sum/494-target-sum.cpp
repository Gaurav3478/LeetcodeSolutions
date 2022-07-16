class Solution {
public:
    int solve(int i, int currSum, int target, map<pair<int, int>, int> &dp, vector<int> &nums) {
        if(i == nums.size()) {
            if(currSum == target) {
                return 1;
            }
            else {
                return 0;
            }
        }
        if(dp.find({i, currSum}) != dp.end()) {
            return dp[{i, currSum}];
        }
        int val = 0;
        val = solve(i + 1, currSum + nums[i], target, dp, nums);
        val += solve(i + 1, currSum - nums[i], target, dp, nums);
        return dp[{i, currSum}] = val;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int currSum = 0;
        int idx = 0;
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++) {
            sum += nums[i];
        }
        map<pair<int, int>, int> dp;
        return solve(idx, currSum, target, dp, nums);
    }
};