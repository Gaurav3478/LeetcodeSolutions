class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1e9)));
        for(int i=0; i<m; i++) {
            for(int j=0; j<m; j++) {
                if(i == j) {
                    dp[n-1][i][j] = grid[n-1][j];
                }
                else {
                    dp[n-1][i][j] = grid[n-1][i] + grid[n-1][j];
                }
            }
        }
        for(int i=n-2; i>=0; i--) {
            for(int j1=0; j1<m; j1++) {
                for(int j2=0; j2<m; j2++) {
                    for(int k=-1; k<=1; k++) {
                        for(int l=-1; l<=1; l++) {
                            if(j1 + k >= 0 && j1 + k < m && j2 + l >=0 && j2+l<m) {
                                if(j1 == j2) {
                                    dp[i][j1][j2] = max(grid[i][j1] + dp[i+1][j1+k][j2+l], dp[i][j1][j2]); 
                                } 
                                else {
                                    dp[i][j1][j2] = max(grid[i][j1] + grid[i][j2] + dp[i+1][j1+k][j2+l], dp[i][j1][j2]); 
                                }
                            }
                        }
                    }
                }
            }
        }
        return dp[0][0][m-1];
        
    }
};