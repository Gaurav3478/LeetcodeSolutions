class Solution {
public:
    const int MOD = 1e9 + 7;
    int dfs(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp, int par) {
        if(min(i, j) < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] <= par) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int up = dfs(i-1, j, grid, dp, grid[i][j]);
        int down = dfs(i+1, j, grid, dp, grid[i][j]);
        int left = dfs(i, j-1, grid, dp, grid[i][j]);
        int right = dfs(i, j+1, grid, dp, grid[i][j]);

        return dp[i][j] = (1 + up%MOD + down%MOD + left%MOD + right%MOD)%MOD; 
    }
    
    int countPaths(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(dp[i][j] == -1) {
                    dfs(i, j, grid, dp, -1);
                }
            }
        }
        int ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                ans  = (ans + dp[i][j])%MOD;
            }
        }
        return ans;
    }
};