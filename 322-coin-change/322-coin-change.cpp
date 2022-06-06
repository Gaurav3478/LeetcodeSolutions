class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, 1e9));
        //what's our base case
        for(int i=0; i<=amount; i++) {
            if(i%coins[0] == 0) {
                dp[0][i] = i/coins[0];   
            }
            else {
               dp[0][i] = 1e9;
            }
        }
        for(int index=1; index<n; index++) {
            for(int value=0; value<=amount; value++) {
                //donttake
                int donttake = dp[index-1][value];
                //take
                int take = INT_MAX;
                if(coins[index] <= value) {
                    take = 1 + dp[index][value - coins[index]];
                }
                dp[index][value] = min(take, donttake);
            }
        }
        if(dp[n-1][amount] >= 1e9) {
            return -1;
        }
        else {
            return dp[n-1][amount];            
        }
    }
};