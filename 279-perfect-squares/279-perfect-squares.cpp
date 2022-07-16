class Solution {
public:
    int numSquares(int n) {
        vector<int> perfectSquares;
        for(int i=1; i<=sqrt(n); i++) {
            perfectSquares.push_back(i*i);
        }
        int sz = perfectSquares.size();
        vector<vector<int>> dp(sz, vector<int>(n+1, 0));
        for(int i=1; i<=n; i++) {
            if(i%perfectSquares[0] == 0) {
                dp[0][i] = i/perfectSquares[0];
            }
        }
        for(int i=1; i<sz; i++) {
            for(int j=1; j<=n; j++) {
                int donttake = dp[i-1][j];
                int take = INT_MAX;
                if(j >= perfectSquares[i]) {
                    take = 1 + dp[i][j - perfectSquares[i]];
                }
                dp[i][j] = min(take, donttake);
            }
        }
        return dp[sz-1][n];
    }
};