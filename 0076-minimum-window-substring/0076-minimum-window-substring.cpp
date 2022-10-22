class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        map<char, int> mpt, mp;
        for(char c: t) {
            mpt[c]++;
        }
        int len = 0;
        int best = INT_MAX;
        string ans = "";
        int i = 0, j = 0;
        while(j < n) {
            char c = s[j];
            if(mpt.find(c) != mpt.end()) {
                mp[c]++;
                if(mp[c] <= mpt[c]) {
                    len++;
                }
            }
            if(len >= m) {
                while(mpt.find(s[i]) == mpt.end() || mp[s[i]] > mpt[s[i]]) {
                    mp[s[i]]--;
                    i++;
                }
                if(j - i + 1 < best) {
                    best = j - i + 1;
                    ans = s.substr(i, j - i + 1);
                }
            }
            j++;
        }
        return (best == INT_MAX ? "" : ans);
    }
};