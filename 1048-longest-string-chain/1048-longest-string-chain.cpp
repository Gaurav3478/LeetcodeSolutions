class Solution {
public:
    static bool cmp(string &a, string &b) {
        return a.size() < b.size();
    }

    bool check(string &s1, string &s2) {
        if(s1.size() - s2.size() != 1) {
            return false;
        }
        int first = 0, second = 0;
        while(first < s1.size()) {
            if(s1[first] == s2[second]) {
                first++;
                second++;
            }
            else {
                first++;
            }
        }
        if(first == s1.size() && second == s2.size()) {
            return true;
        }
        else {
            return false;
        }
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<int> dp(n, 1);
        int ans = 0;
        sort(words.begin(), words.end(), cmp);
        for(int i=0; i<n; i++) {
            for(int j=0; j<i; j++) {
                //check if j'th word can make chain with i'th word
                if(check(words[i], words[j])) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            ans = max(ans, dp[i]);
        } 
        return ans;  
    }
};