class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(k+1, 0));
        int val = 0;
        for(int i=1; i<=min(k, (int)piles[0].size()); i++) {
            dp[0][i] = val + piles[0][i-1];
            val += piles[0][i-1]; 
        }
        for(int i=1; i<n; i++) {
            for(int j=0; j<=k; j++) {
                dp[i][j] = dp[i-1][j];
                int s = 0;
                for(int x=1; x<=min({j, k, (int)piles[i].size()}); x++) {
                    s += piles[i][x-1];
                    dp[i][j] = max(dp[i][j], dp[i-1][j-x] + (x-1>=0?s:0));
                }
            }
        }
        return dp[n-1][k];
    }
};