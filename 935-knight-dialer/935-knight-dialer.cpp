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
        if(n < 0) {
            return 0;
        }
        if(dp[i][j][n] != -1) {
            return dp[i][j][n];
        }
        int val = 0;
        for(int k=0; k<8; k++) {
            int v1 = directions[k][0];
            int v2 = directions[k][1];
            int nr = i + v1;
            int nc = j + v2;
            if(isValid(nr, nc)) {
                val = (val%MOD + solve(nr, nc, n-1, dp)%MOD)%MOD;
            }
        }
        return dp[i][j][n] = val%MOD;
    }
    
    int knightDialer(int n) {
        //we know our grid is effectively 4 rows and 3 columns, except the fourth row 1st column and fourth row 3rd column are not part of this grid
        int ans = 0;
        vector<vector<vector<int>>> dp(4, vector<vector<int>>(3, vector<int>(n+1, -1)));
        for(int i=0; i<4; i++) {
            for(int j=0; j<3; j++) {
                ans = (ans%MOD + solve(i, j, n, dp)%MOD)%MOD;
            }
        }
        return ans%MOD;
    }
};