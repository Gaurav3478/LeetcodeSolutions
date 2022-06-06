class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, 0));
        //dp[i][j] represents that with the first i coins, how many ways can we make an amount j
        //suppose we had 1 coin only, then the number of ways would be 1 if and only if the amount would be equal to the coin
        for(int i=0; i<=amount; i++) {
            if(i%coins[0] == 0) {
                dp[0][i] = 1;
            }
            else {
                dp[0][i] = 0;
            }
        }
        for(int i=1; i<n; i++) {
            for(int j=0; j<=amount; j++) {
                int donttake = dp[i-1][j];
                //we only want to take if it makes some sort of sense
                int take = 0;
                if(coins[i] <= j) {
                    take = dp[i][j-coins[i]];
                }
                dp[i][j] = take + donttake;
            }
        }
        return dp[n-1][amount];
    }
};