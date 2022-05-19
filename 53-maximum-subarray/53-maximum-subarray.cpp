class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1);
        dp[0] = 0;
        int ans = nums[0];
        for(int i=1; i<=n; i++) {
            dp[i] = nums[i-1] + (dp[i-1] > 0? dp[i-1]:0);
            ans = max(dp[i], ans);
        }
        return ans;
    }
};