class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MIN));
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(j < i) {
                    dp[i][j] = 0;
                }
            }
        }
        for(int i=n-2; i>=1; i--) {
            for(int j=i; j<=n-2; j++) {
                for(int k=i; k<=j; k++) {
                    dp[i][j] = max(dp[i][j], nums[i-1]*nums[k]*nums[j+1] + dp[i][k-1] + 
                dp[k+1][j]);
                }
            }
        }
        return dp[1][n-2];
    }
};