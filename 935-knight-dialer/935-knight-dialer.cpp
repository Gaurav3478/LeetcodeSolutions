class Solution {
public:
    const int MOD = (int) 1e9 + 7;
    vector<vector<int>> directions = {{-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {-1, -2}, {1, -2}}; 

    bool isValid(int i, int j) {
        if(min(i, j) < 0 || i >= 4 || j >= 3 || (i == 3 && j != 1)) {
            return false;
        }
        return true;
    }
    
    int solve(int i, int j, int n, vector<vector<vector<int>>> &dp) {
        if(!isValid(i, j)) {
            return 0;
        }
        if(n == 1) {
            return 1;
        }
        if(dp[i][j][n] != -1) {
            return dp[i][j][n];
        }
        int val = 0;
        for(auto &dir: directions) {
            int nr = i + dir[0];
            int nc = j + dir[1];
            val = (val + solve(nr, nc, n-1, dp))%MOD;
        }
        return dp[i][j][n] = val;
    }
    
    int knightDialer(int n) {
        //we know our grid is effectively 4 rows and 3 columns, except the fourth row 1st column and fourth row 3rd column are not part of this grid
        int ans = 0;
        vector<vector<vector<int>>> dp(4, vector<vector<int>>(3, vector<int>(n+1, -1)));
        for(int i=0; i<4; i++) {
            for(int j=0; j<3; j++) {
                ans = (ans + solve(i, j, n, dp))%MOD;
            }
        }
        return ans;
    }
};