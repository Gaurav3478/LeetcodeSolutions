class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int localMax = 0, globalMax = INT_MIN;
        for(int i=0; i<n; i++) {
            localMax = max(nums[i], localMax + nums[i]);
            if(localMax > globalMax) {
                globalMax = localMax;
            }
        }
        return globalMax;
    }
};