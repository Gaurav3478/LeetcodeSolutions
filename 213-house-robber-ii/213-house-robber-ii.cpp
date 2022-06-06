class Solution {
public:
    int f(vector<int> &nums, int start, int end) {
        vector<int> dp(nums.size(), 0);
        dp[start] = nums[start];
        for(int i=start+1; i<end; i++) {
            int donttake = dp[i-1];
            int take = nums[i];
            if(i > 1) {
                take += dp[i-2];
            }
            dp[i] = max(take, donttake);
        }
        return dp[end-1];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) {
            return nums[0];
        }
        return max(f(nums, 0, n-1), f(nums, 1, n));
    }
};