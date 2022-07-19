class Solution {
public:
    const int MOD = 1e9 + 7;
    int solve(int n, vector<int> &rollMax, int prev, int cons, vector<vector<vector<int>>> &dp) {
        if(n == 0) {
            return 1;
        }
        if(prev != -1 && dp[n][prev][cons] != -1) {
            return dp[n][prev][cons];
        }
        int val = 0;
        for(int i=0; i<6; i++) {
            if(i == prev && cons == rollMax[i]) {
                continue;
            }
            if(i == prev) {
                val = (val + solve(n-1, rollMax, i, cons + 1, dp))%MOD;
            }
            else {
                val = (val + solve(n-1, rollMax, i, 1, dp))%MOD;
            }
        }
        if(prev != -1) {
            dp[n][prev][cons] = val;
        }
        return val;
    }
    
    int dieSimulator(int n, vector<int>& rollMax) {
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(6, vector<int>(16, -1)));
        return solve(n, rollMax, -1, 0, dp);
    }
};