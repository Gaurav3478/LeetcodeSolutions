class Solution {
public:
    const int mod = (int) 1e9 + 7; 
    
    int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2}; 
    int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1}; 
    
    bool safe(int x, int y) {
        if(x == 3 and (y == 0 or y == 2)) return false; 
        if(x < 0 or x > 3) return false; 
        if(y < 0 or y > 2) return false; 
        return true; 
    }
    
    int f(int x, int y, int n, vector<vector<vector<int>>>& dp) {
        if(!safe(x, y)) return 0;
        if(n == 1) return 1;
        if(n < 0) return 0; 
        
        if(dp[x][y][n] != -1) return dp[x][y][n]; 
        
        int cnt = 0;
        
        for(int k = 0; k < 8; k++) {
            int i = x + dx[k]; 
            int j = y + dy[k]; 
            if(safe(i, j)) {
                cnt = (cnt % mod + f(i, j, n - 1, dp) % mod) % mod; 
            }
        }
        return dp[x][y][n] = cnt % mod; 
    }
    
    int knightDialer(int n) {
        int cnt = 0; 
        vector<vector<vector<int>>> dp(4, vector<vector<int>>(3, vector<int>(n + 1,-1))); 
        
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 3; j++) {
                cnt = (cnt % mod + f(i, j, n, dp) % mod) % mod; 
            }
        }
        return cnt % mod; 
    }
};