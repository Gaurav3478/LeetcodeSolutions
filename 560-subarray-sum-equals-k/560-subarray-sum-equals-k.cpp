class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        vector<int> pref(n+1, 0);
        for(int i=0; i<n; i++) {
            pref[i+1] = pref[i] + nums[i];
        }
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++) {
            int cur = pref[i+1];
            if(cur == k) {
                ans++;
            }
            if(mp.find(cur - k) != mp.end()) {
                ans += mp[cur-k];
            }
            mp[cur]++;
        }
        return ans;
    }
};