class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1, mid, ans;
        int index;
        // while(low <= high) {
        //     mid = low + (high - low)/2;
        //     if(nums[mid] < nums[mid-1]) {
        //         index = mid;
        //         break;
        //     }
        //     if(nums[mid] < nums[low]) {
        //         high = mid - 1;
        //     }
        //     else {
        //         low = mid;
        //     }
        // }
        while(low<high){
            mid=(low+high)/2;
            if(nums[mid]>nums[high]) low=mid+1;
            else high=mid;
        }
        //now the index contains the actual first element of the array
        //now I basically want to do another binary search
        index = high;  
        low = 0, high = n-1;
        int realmid;
        while(low <= high) {
            mid = low + (high - low)/2;
            realmid = (mid+index)%n;
            if(nums[realmid] == target) {
                return realmid;
            }
            if(nums[realmid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return -1;
    }
};