class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n-1;   
        //find point where left is greater and right is greater
        while(low < high){
            int mid=(low+high)/2;
            if(nums[mid]>nums[high]) low=mid+1;
            else high=mid;
        }
        return nums[low];
    }
};