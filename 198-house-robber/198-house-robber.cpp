class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0); 
        dp[0] = nums[0];
        for(int i=1; i<n; i++) {
            //dont steal
            int dontsteal = dp[i-1];
            //steal
            int steal = nums[i];
            if(i > 1) {
                steal = dp[i-2] + nums[i];
            }
            dp[i] = max(steal, dontsteal);
        }        
        return dp[n-1];
    }
};