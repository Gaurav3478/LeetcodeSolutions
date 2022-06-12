class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> count(n, 1);
        int ans = 0;
        //dp[i] represents the LIS until index i
        for(int i=0; i<n; i++) {
            for(int j=0; j<i; j++) {
                if(nums[i] > nums[j] && 1 + dp[j] > dp[i]) {
                    dp[i] = 1 + dp[j];
                    count[i] = count[j];
                }
                else if(nums[i] > nums[j] && 1 + dp[j] == dp[i]) {
                    count[i] += count[j];
                }
            }
            ans = max(ans, dp[i]);
        }
        int cnt = 0;
        for(int i=0; i<n; i++) {
            if(dp[i] == ans) {
                cnt += count[i];
            }
        }
        return cnt;
    }
};