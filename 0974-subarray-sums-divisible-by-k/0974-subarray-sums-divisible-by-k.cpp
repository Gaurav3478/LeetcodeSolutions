class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pref(n + 1, 0);
        for(int i=0; i<n; i++) {
            pref[i + 1] = pref[i] + nums[i];
        }
        
        map<int, int> mp;
        mp[0]++;
        int ans = 0;
        for(int i=1; i<=n; i++) {
            int cur = pref[i];
            int rem;
            if(cur < 0) {
                rem = (k + cur % k) % k;
            }
            else {
                rem = cur % k;
            }
            ans += mp[rem];
            mp[rem]++;
        }
        return ans;
    }
};