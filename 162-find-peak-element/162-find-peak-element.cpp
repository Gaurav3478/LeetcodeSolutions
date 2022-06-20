class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int L = 0, R = n-1;
        while(L < R) {
            int m = (L+R+1)/2;
            if(nums[m-1] > nums[m]) {
                R = m-1;
            }
            else {
                L = m;
            }
        }
        return L;
    }
};