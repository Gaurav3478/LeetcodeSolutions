class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int n = words.size();
        map<string, int> mp;
        for(int i=0; i<n; i++) {
            mp[words[i]]++;
        }
        
        int ans = 0;
        bool seenOdd = false;
        map<string, bool> vis;
        for(auto ele: mp) {
            string s = ele.first;
            int freq = ele.second;
            if(vis[s]) {
                continue;
            }
            if(s[0] == s[1]) {
                if(freq % 2) {
                    seenOdd = true;
                }
                if(freq % 2 == 1) {
                    freq--;
                }
                ans += freq * 2;
            }
            else {
                string s2 = s;
                reverse(s2.begin(), s2.end());
                if(mp.find(s2) == mp.end()) {
                }
                else {
                    vis[s2] = true;
                    int freq2 = mp[s2];
                    ans += 4*min(freq, freq2);
                }
            }
            vis[s] = true;
        }
        
        if(seenOdd) {
            ans += 2;
        }
        
        return ans;
    }
};