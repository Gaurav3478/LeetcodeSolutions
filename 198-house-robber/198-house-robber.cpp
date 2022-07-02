class Solution {
public:
    int rob(vector<int>& nums) {
        //all that matters in our current choice is whether we took the last element or not
        //for each house, make a choice: take or don't take
        int n = nums.size();
        vector<int> dp(n, 0);
        //dp[i] represents the maximum possible value given that we are ending at index i
        dp[0] = nums[0];
        if(n > 1) {
            dp[1] = max(nums[0], nums[1]);
        }
        for(int i=2; i<n; i++) {
            int donttake = dp[i-1];
            int take = dp[i-2] + nums[i];
            dp[i] = max(take, donttake);
        }
        return dp[n-1];
    }
};