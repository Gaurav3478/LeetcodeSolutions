class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
        for(int i=0; i<=n; i++) {
            for(int j=0; j<2; j++) {
                dp[i][j][0] = 0;
            }
        }
        for(int i=0; i<2; i++) {
            for(int j=0; j<3; j++) {
                dp[n][i][j] = 0;
            }
        }
        for(int i=n-1; i>=0; i--) {
            for(int j=0; j<2; j++) {
                for(int k=1; k<3; k++) {
                    if(j == 1) {
                        //we can buy
                        dp[i][j][k] = max(-prices[i] + dp[i+1][0][k], dp[i+1][1][k]);
                    }
                    else {
                        dp[i][j][k] = max(prices[i] + dp[i+1][1][k-1], dp[i+1][0][k]);
                    }
                }
            }
        }
        return dp[0][1][2];
    }
};