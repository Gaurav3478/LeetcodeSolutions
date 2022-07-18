class Solution {
public:
   vector<vector<int>> directions = {{-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {-1, -2}, {1, -2}}; 
    
    double solve(int n, int k, int row, int column, vector<vector<vector<double>>> &dp) {
        if(min(row, column) < 0 || max(row, column) >= n) {
            return 0;
        }
        if(k == 0) {
            return 1;
        }
        if(dp[row][column][k] != -1) {
            return dp[row][column][k];
        } 
        double val = 0;
        for(auto dir: directions) {
            int nr = row + dir[0];
            int nc = column + dir[1];
            val += solve(n, k-1, nr, nc, dp);
        }
        val = val/8;
        return dp[row][column][k] = val;
    }
    
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(n, vector<vector<double>>(n, vector<double>(k + 1, -1)));
        return solve(n, k, row, column, dp);
    }
};