class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int count = 0;
        int i = 0;
        while(i < n) {
            if(nums[i] != 1) {
                i++;
                continue;
            }
            count = 1;
            int j = i+1;
            while(j < n && nums[j] == 1) {
                count++;
                j++;
                if(j == n) {
                    break;
                }
            }
            i = j;
            ans = max(ans, count);
        }
        return ans;
    }   
};