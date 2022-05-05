class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n-1;
        int mid, num;
        while(low < high) {
            int mid = low + (high - low)/2;
            num = mid%2==0?mid+1:mid-1;
            if(nums[num] == nums[mid]) {
                low = mid + 1;
            }
            else {
                high = mid;
            }
        }
        return nums[low];
    }
};