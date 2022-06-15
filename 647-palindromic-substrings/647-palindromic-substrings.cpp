class Solution {
public:
    bool is_palindrome(string s) {
        int n = s.size();
        for(int i=0; i<=n/2 - 1; i++) {
            if(s[i] != s[n-1-i]) {
                return false;
            }
        }
        return true;
    }

    int countSubstrings(string s) {
        int n = s.size();
        vector<int> dp(n, 0);
        dp[0] = 1;
        for(int i=1; i<n; i++) {
            //dp[i] = dp[i-1] + # palindromes ending at i
            dp[i] = dp[i-1] + 1;
            for(int j=0; j<i; j++) {
                if(is_palindrome(s.substr(j, i-j+1))) {
                    dp[i]++;
                }
            }
        }
        return dp[n-1];
    }
};