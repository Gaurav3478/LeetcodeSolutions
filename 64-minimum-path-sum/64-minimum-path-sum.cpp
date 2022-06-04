class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        //can move only down or right
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(i==0 && j==0) {
                    dp[i][j] = grid[i][j];
                }
                else if(i == 0) {
                    dp[i][j] = dp[i][j-1] + grid[i][j];
                }
                else if(j == 0) {
                    dp[i][j] = dp[i-1][j] + grid[i][j];
                }
                else{
                    dp[i][j] = grid[i][j] + min(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        return dp[n-1][m-1];
    }
};