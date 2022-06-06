class Solution {
public:
    int findWays(vector<int> &nums, int tar) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(tar+1, 0));
    if(nums[0] == 0) {
        dp[0][0] = 2;
    }
    else {
        dp[0][0] = 1;
    }
    if(nums[0] != 0 && nums[0] <= tar) {
        dp[0][nums[0]] = 1;
    }
    for(int ind=1; ind<n; ind++) {
        for(int sum=0; sum<=tar; sum++) {
            int notTake = dp[ind-1][sum];
            int take = 0;
            if(nums[ind] <= sum) {
                take = dp[ind-1][sum-nums[ind]];
            }
            dp[ind][sum] = notTake + take;
        }
    }
    return dp[n-1][tar];
}

int countPartitions(int n, int d, vector<int> &arr) {
    int totSum = 0;
    for(auto &it: arr) {
        totSum += it;
    }
    if(totSum - d < 0 || (totSum-d)%2) {
        return false;
    }
    return findWays(arr, (totSum - d)/2);
}

int findTargetSumWays(vector<int>& nums, int target) {
    int n = nums.size();
    return countPartitions(n, target, nums);        
}
};