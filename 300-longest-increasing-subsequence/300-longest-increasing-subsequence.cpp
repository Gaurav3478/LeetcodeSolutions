class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        //dp[i] represents the LIS until index i
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                if(nums[j] > nums[i]) {
                    dp[j] = max(dp[j], 1 + dp[i]);
                }
            }
        }
        int ans = 0;
        for(int i=0; i<n; i++) {
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};