class Solution {
public:
    bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n, vector<bool>(k+1, false));
    for(int i=0; i<n; i++) {
        dp[i][0] = true;
    } 
    if(arr[0] <= k) {
        dp[0][arr[0]] = true;
    }
    for(int i=1; i<n; i++) {
        for(int j = 1; j<=k; j++) {
            bool donttake = dp[i-1][j];
            bool take = false;
            if(arr[i] <= j) {
                take = dp[i-1][j-arr[i]];
            }
            dp[i][j] = take || donttake;
        }
    }
    return dp[n-1][k];
}

    bool canPartition(vector<int>& nums) {
        //each number must be part of subset A or subset B
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++) {
            sum += nums[i];
        }
        int target = sum/2;
        if(sum%2==1) {
            return false;
        }
        return subsetSumToK(n, target, nums);
    }
};