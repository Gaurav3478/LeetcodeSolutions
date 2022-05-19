class Solution {
public:
    int climbStairs(int n) {
        //in either turn we can climb either 1 step or 2 steps
        vector<int> dp(n+1);
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2; i<=n; i++) {
            dp[i] = dp[i-1] + dp[i-2]; 
        }
        return dp[n];
    }
};