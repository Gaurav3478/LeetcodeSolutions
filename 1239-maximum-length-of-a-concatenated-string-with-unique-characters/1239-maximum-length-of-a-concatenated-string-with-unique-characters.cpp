class Solution {
public:
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        int ans = 0;
        for(int mask = 1; mask < (1 << n); mask++) {
            string s = "";
            for(int i=0; i<n; i++) {
                if(mask & (1 << i)) {
                    s += arr[i];
                }
            }
            if(s.size() > 26) {
                continue;
            }
            map<char, int> mp;
            bool ok = true;
            for(char c: s) {
                mp[c]++;
                if(mp[c] > 1) {
                    ok = false;
                    break;
                }
            }
            if(ok) {
                ans = max(ans, (int)s.size());
            }
        }
        
        return ans;
    }
};