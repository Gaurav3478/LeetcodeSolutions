class Solution {
public:
    vector<vector<int>> longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(text1[i-1] == text2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp;
    }

    string shortestCommonSupersequence(string str1, string str2) {
        //use dp table of lcs
        vector<vector<int>> table = longestCommonSubsequence(str1, str2);
        int n = str1.size();
        int m = str2.size();
        string ans;
        int i = n, j = m;
        while(i > 0 && j > 0) {
            if(str1[i-1] == str2[j-1]) {
                ans += str1[i-1];
                i--;
                j--;
            }
            else if(table[i-1][j] > table[i][j-1]) {
                ans += str1[i-1];
                i--;
            }
            else {
                ans += str2[j-1];
                j--;
            }
        }
        while(i > 0) {
            ans += str1[i-1];
            i--;
        }
        while(j > 0) {
            ans += str2[j-1];
            j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};