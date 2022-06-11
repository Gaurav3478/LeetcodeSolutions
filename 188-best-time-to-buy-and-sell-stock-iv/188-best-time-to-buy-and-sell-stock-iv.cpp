class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));
        for(int i=n-1; i>=0; i--) {
            for(int j=0; j<2; j++) {
                for(int l=1; l<k+1; l++) {
                    if(j == 1) {
                        //we can buy
                        dp[i][j][l] = max(-prices[i] + dp[i+1][0][l], dp[i+1][1][l]);
                    }
                    else {
                        dp[i][j][l] = max(prices[i] + dp[i+1][1][l-1], dp[i+1][0][l]);
                    }
                }
            }
        }
        return dp[0][1][k];
    }
};