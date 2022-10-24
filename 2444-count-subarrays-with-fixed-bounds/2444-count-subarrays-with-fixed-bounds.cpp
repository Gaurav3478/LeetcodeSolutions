class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int n = nums.size();
        long long min_idx = -1, max_idx = -1, bad = -1;
        for(int i=0; i<n; i++) {
            if(nums[i] == minK) {
                min_idx = i;
            }
            if(nums[i] == maxK) {
                max_idx = i;
            }
            if(nums[i] > maxK || nums[i] < minK) {
                bad = i;
            }
            ans += max(0ll, min(min_idx, max_idx) - bad);
        }
        return ans;
    }
};