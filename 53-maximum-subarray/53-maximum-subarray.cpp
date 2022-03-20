class Solution {
public:
    int maxSubArray(vector<int>& nums) {
//         int n = nums.size();
//         int max_so_far, current_sum = 0;
//         current_sum = nums[0];
//         max_so_far = current_sum;
        
//         for(int i=1; i<n; i++) {
//             if(current_sum + nums[i] > 0) {
//                 current_sum = max(current_sum + nums[i], nums[i]);
//             }
//             else {
//                 current_sum = nums[i];
//             }
//             if(current_sum > max_so_far) {
//                 max_so_far = current_sum;
//             }
//         }
//         return max_so_far;
        int n = nums.size();
        int sum_so_far = 0;
        int ans = nums[0];
        for(int i=0; i<n; i++) {
            if(sum_so_far + nums[i] > 0) {
                sum_so_far = max(sum_so_far + nums[i], nums[i]);
            }
            else {
                sum_so_far = nums[i];
            }
            ans = max(ans, sum_so_far);
        }
        return ans;
    }
};