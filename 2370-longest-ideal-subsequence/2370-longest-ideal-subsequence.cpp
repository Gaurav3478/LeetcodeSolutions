class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(26, 0));
        dp[0][s[0] - 97] = 1;
        for(int i=1; i<n; i++) {
            int c_no = s[i] - 97;
            for(int j=0; j<26; j++) {
                if(j >= c_no - k && j <= c_no + k) {
                    dp[i][c_no] = max(dp[i][c_no], dp[i-1][j] + 1);
                }
                dp[i][j] = max(dp[i][j], dp[i-1][j]);
            }
        }
        return *max_element(dp[n-1].begin(), dp[n-1].end());
    }
};