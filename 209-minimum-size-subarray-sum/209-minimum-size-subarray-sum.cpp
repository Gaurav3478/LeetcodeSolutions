class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len = INT_MAX;
        int i = 0, j = 0;
        int n = nums.size();
        int curr_sum = 0;
        while(j < n && i <= j) {
            curr_sum += nums[j];
            if(curr_sum >= target) {
                len = min(len, j - i + 1);
                curr_sum -= nums[j];
                curr_sum -= nums[i];
                i++;
            }
            else {
                j++;
            }
        }
        if(len == INT_MAX) {
            return 0;
        }
        else {
            return len;
        }
    }
};