class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        map<char, int> mp;
        int i=0, j=0;
        int ans = 0;
        while(j < n) {
            mp[s[j]]++;
            while(mp.size() < j - i + 1) {
                if(mp[s[i]] == 1) {
                    mp.erase(s[i]);
                }
                else {
                    mp[s[i]]--;
                }
                i++;
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};