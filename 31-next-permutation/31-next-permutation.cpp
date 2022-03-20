class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i;
        for(i=n-2; i>=0; i--) {
            if(nums[i] < nums[i+1]) {
                break;
            }
        }
        if(i == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        int l;
        for(l = n-1; l>i; l--) {
            if(nums[l] > nums[i]) {
                break;
            }
        }
        swap(nums[i], nums[l]);
        reverse(nums.begin() + 1 + i, nums.end());
        
    }
};