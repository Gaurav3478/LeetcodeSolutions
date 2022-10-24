class Solution {
public:
    int maxLength(vector<string>& arr) {
        //my plan is to try all subsets of words, literally concatenate them and see what the result is
        int n = arr.size();
        int ans = 0;
        //I need numbers from 0 to 2^n - 1 inclusive
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
            bool ok = true;
            sort(s.begin(), s.end());
            for(int i=1; i<s.size(); i++) {
                if(s[i] == s[i - 1]) {
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