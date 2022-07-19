class Solution {
public:
    double solve(int a, int b, vector<vector<double>> &dp) {
        if(a <= 0 && b > 0) {
            return 1;
        }
        else if(a <= 0 && b <= 0) {
            return 0.5;
        }
        else if(b <= 0 && a > 0) {
            return 0;
        }
        if(dp[a][b] != -1) {
            return dp[a][b];
        }
        double val = 0;
        val += solve(a-100, b, dp);
        val += solve(a-75, b-25, dp);
        val += solve(a-50, b-50, dp);
        val += solve(a-25, b-75, dp);
        return dp[a][b] = 0.25*val;
    }
    
    double soupServings(int n) {
        if(n >= 5000) {
            return 1.0;
        }
        else {
            vector<vector<double>> dp(n+1, vector<double>(n+1, -1));
            return solve(n, n, dp);
        }
    }
};