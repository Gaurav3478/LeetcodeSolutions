class Solution {
public:
    const int MOD = 1e9 + 7;
    int kInversePairs(int n, int k) {
        vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
        //dp[i][j] represents the inverse pairs if we have i integers (1 -> i) and there are k inverse pairs
        for(int i=0; i<=n; i++) {
            dp[i][0] = 1;
        }
        for(int i=2; i<=n; i++) {
            for(int j=1; j<=k; j++) {
                dp[i][j] = (dp[i-1][j] + (j>0?dp[i][j-1]:0))%MOD;
                if(j >= i) {
                    dp[i][j] = (dp[i][j] - dp[i-1][j-i] + MOD)%MOD;
                }
            }
        }
        return dp[n][k];
    }
};