class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int i=0; i<n; i++) {
            dp[i][i] = true;
        }
        int count = n;
        for(int len = 2; len <= n; len++) {
            for(int i=0; i+len -1<=n-1; i++) {
                int j = i + len -1;
                if(s[i] != s[j]) {
                    dp[i][j] = false;
                }
                else {
                    if(len == 2) {
                        dp[i][j] = true;
                    }
                    else {
                        dp[i][j] = dp[i+1][j-1];
                    }
                }
                count += dp[i][j];
            }
        }
        return count;
    }
};