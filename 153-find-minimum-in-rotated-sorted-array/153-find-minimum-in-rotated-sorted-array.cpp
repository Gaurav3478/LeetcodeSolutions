class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n-1;   
        //find point where left is greater and right is greater
        while(low < high) {
            int mid = low + (high - low)/2;
            if(nums[low] < nums[high]) {
                //there is no rotation
                return nums[low];
            }
            else {
                if(nums[mid] >= nums[low]) {
                    low = mid + 1;
                }
                else {
                    high = mid;
                }
            }
        }
        return nums[low];
    }
};