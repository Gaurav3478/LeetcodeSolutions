class Solution {
public:
    int ans = 0;
    const int MOD = 1e9 + 7;
    bool isValid(int i, int j, int m, int n) {
        if(min(i, j) < 0 || i>=m || j >= n) {
            return false;
        }
        return true;
    }
    
    int solve(int i, int j, int m, int n, int moves, int maxMoves, vector<vector<vector<int>>> &dp) {
        if(!isValid(i, j, m, n)) {
            return 1;
        }
        if(moves == maxMoves) {
            return 0;
        }
        if(dp[moves][i][j] != -1) {
            return dp[moves][i][j];
        }
        int val = 0;
        val = (val + solve(i+1, j, m, n, moves + 1, maxMoves, dp))%MOD;
        val = (val + solve(i-1, j, m, n, moves + 1, maxMoves, dp))%MOD;
        val = (val + solve(i, j+1, m, n, moves + 1, maxMoves, dp))%MOD;
        val = (val + solve(i, j-1, m, n, moves + 1, maxMoves, dp))%MOD;
        return dp[moves][i][j] = val;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(maxMove+1, vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        return solve(startRow, startColumn, m, n, 0, maxMove, dp);
    }
};