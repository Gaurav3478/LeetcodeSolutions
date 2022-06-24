class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        int target = 0;
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i=0; i<n-2; i++) {
            while(i < n && i > 0 && nums[i] == nums[i-1]) {
                i++;
            }
            if(i>=n-2 || nums[i] > 0) {
                break;
            }
            int left = i+1, right = n-1;
            while(left < right) {
                int cur_sum = nums[i] + nums[left] + nums[right];
                if(cur_sum > 0) {
                    right--;
                }
                else if(cur_sum < 0) {
                    left++;
                }
                else {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[left]);
                    temp.push_back(nums[right]);
                    ans.push_back(temp);
                    while(left < n && left < right && nums[left] == nums[left+1]) {
                        left++;
                    }
                    left++;
                    while(right > 0 && right > left && nums[right] == nums[right-1]) {
                        right--;
                    }
                    right--;
                }
            }
        }
        return ans;
    }
};