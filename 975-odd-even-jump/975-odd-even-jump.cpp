class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();
        int res = 0;
        vector<bool> oddJump(n, false), evenJump(n, false);
        oddJump[n-1] = evenJump[n-1] = true;
        map<int, int> mp;
        for(int i=n-1; i>=0; i--) {
            auto hi = mp.lower_bound(arr[i]);
            auto lo = mp.upper_bound(arr[i]);
            if(hi != mp.end()) {
                oddJump[i] = evenJump[hi->second];
            }
            if(lo != mp.begin()) {
                lo--;
                evenJump[i] = oddJump[lo->second];
            }
            if(oddJump[i]) {
                res++;
            }
            mp[arr[i]] = i;
        }
        return res;
    }
};