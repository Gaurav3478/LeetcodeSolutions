class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> prev(n, -1);
        for(int i=0; i<n; i++) {
            for(int j=0; j<i; j++) {
                if(nums[j] < nums[i]) {
                    if(1 + dp[j] > dp[i]) {
                        dp[i] = 1 + dp[j];
                        prev[i] = j;
                    }
                }
            }
        }
        int maxi = *max_element(dp.begin(), dp.end());
        int idx;
        for(int i=0; i<n; i++) {
            if(dp[i] == maxi) {
                idx = i;
                break;
            }
        }
        vector<int> ans;
        while(idx != -1) {
            ans.push_back(nums[idx]);
            idx = prev[idx];
        }
        reverse(ans.begin(), ans.end());
        for(auto ele: ans) {
            cout << ele << " ";
        }
        cout << endl;
        return *max_element(dp.begin(), dp.end());
    }
};