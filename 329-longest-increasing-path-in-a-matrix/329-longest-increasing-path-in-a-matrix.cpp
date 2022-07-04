class Solution {
public:
    int dfs(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp, int par) {
        if(min(i, j) < 0 || i >= matrix.size() || j >= matrix[0].size() || matrix[i][j] <= par) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int up = dfs(i-1, j, matrix, dp, matrix[i][j]);
        int down = dfs(i+1, j, matrix, dp, matrix[i][j]);
        int left = dfs(i, j-1, matrix, dp, matrix[i][j]);
        int right = dfs(i, j+1, matrix, dp, matrix[i][j]);

        return dp[i][j] = 1 + max({up, down, left, right});
    }
     
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(dp[i][j] == -1) {
                    dfs(i, j, matrix, dp, -1);
                }
            }
        }
        int ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};