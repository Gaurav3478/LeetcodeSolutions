class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        //take donttake
        vector<vector<int>> dp(n, vector<int>(amount+1, 0));
        for(int i=0; i<=amount; i++) {
            if(i%coins[0] == 0 ) {
                dp[0][i] = i/coins[0];
            }
            else {
                dp[0][i] = 1e9;
            }
        }                   
        for(int i=1; i<n; i++) {
            for(int j=0; j<=amount; j++) {
                int donttake = dp[i-1][j];
                int take = 1e9;
                if(coins[i] <= j) {
                    take = 1 + dp[i][j-coins[i]];
                }
                dp[i][j] = min(take, donttake);
            }
        }
        return dp[n-1][amount] >= 1e9?-1:dp[n-1][amount];
    }
};