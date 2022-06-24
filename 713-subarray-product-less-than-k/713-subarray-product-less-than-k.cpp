class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        //very simple two pointer approach
        int n = nums.size();
        int l = 0, r = 0;
        int ans = 0;
        int cur_prod = 1;
        if(k == 0 || k == 1) {
            return 0;
        }
        while(r < n) {
            cur_prod *= nums[r];
            while(cur_prod >= k) {
                cur_prod /= nums[l];
                l++;
            }
            if(cur_prod < k) {
                ans += (r - l + 1);
            }
            r++;
        }
        return ans;
    }
};