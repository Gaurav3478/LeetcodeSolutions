class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.size();
        vector<int> dp(26, 0);
        int ans = 1;
        for(int i=0; i<n; i++) {
            char c = s[i];
            int c_no = c - 97;
            dp[c_no]++;
            for(int j=max(0, c_no-k); j<=min(25, c_no+k); j++) {
                if(j != c_no) {
                    dp[c_no] = max(dp[c_no], dp[j] + 1);
                }
            }
            ans = max(ans, dp[c_no]);
        }
        return ans;
    }
};