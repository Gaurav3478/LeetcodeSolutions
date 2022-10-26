class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> mp;
        int prev = 0;
        mp[0] = 1;
        int sum = 0;
        for(int i=0; i<n; i++) {
            sum += nums[i];
            int rem = sum % k;
            if(mp.find(rem) != mp.end() && (mp[rem] > 1 || prev != rem)) {
                return true;
            }
            mp[rem]++;
            prev = rem;
        }
        return false;
    }
};