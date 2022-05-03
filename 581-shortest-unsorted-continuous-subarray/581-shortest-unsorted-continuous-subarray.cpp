class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int start = 0;
        int n = nums.size();
        int rightVal = nums[n-1];
        for(int i = n-2; i>=0; i--) {
            if(rightVal < nums[i]) {
                start = i;
            }
            else {
                rightVal = nums[i];
            }
        }
        int end = -1;
        int leftVal = nums[0];
        for(int i=0; i<n; i++) {
            if(leftVal > nums[i]) {
                end = i;
            }
            else {
                leftVal = nums[i];
            }
        }
        return end - start + 1;
    }
};