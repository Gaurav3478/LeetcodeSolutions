class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = INT_MAX;
        int minDiff = INT_MAX;
        for(int i=0; i<n-2; i++) {
            int left = i+1, right = n-1;
            while(left < right) {
                int cur_sum = nums[i] + nums[left] + nums[right];
                if(cur_sum == target) {
                    return target;
                }
                else if(cur_sum > target) {
                    if(cur_sum - target < minDiff) {
                        minDiff = cur_sum - target;
                        ans = cur_sum;
                    }
                    right--;
                }
                else {
                    if(target - cur_sum < minDiff) {
                        minDiff = target - cur_sum;
                        ans = cur_sum;
                    }
                    left++;
                }
            }
        }
        return ans;
    }
};