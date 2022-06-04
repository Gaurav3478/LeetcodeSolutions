class Solution {
public:
    int uniquePaths(int m, int n) {
        //2d DP
        vector<vector<int>> dp(m, vector<int>(n));
        //dp[i][j] represents how many ways there are to get to the current cell
        //in general dp[i][j] = dp[i-1][j] + dp[i][j-1]
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(i == 0 && j == 0) {
                    dp[i][j] = 1;
                }
                else if(i == 0) {
                    dp[i][j] = dp[i][j-1];
                }
                else if(j == 0) {
                    dp[i][j] = dp[i-1][j];
                }
                else {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }    
        return dp[m-1][n-1];  
    }
};