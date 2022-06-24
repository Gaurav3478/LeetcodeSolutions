class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n-1;
        int i = 0;
        while(i < n && nums[i] == 0) {
            i++;
        }
        for(int j=i; j<n; j++) {
            if(nums[j] == 0) {
                swap(nums[j], nums[i]);
                i++;
            }
        }
        //zeroes should be sorted
        for(int j=i; j<n; j++) {
            if(nums[j] == 1) {
                swap(nums[j], nums[i]);
                i++;
            }
        }
    }
};