class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i_swap = 0, j_swap = 0;
        int current_min = 101;
        for(int i=0; i<n; i++) {
            for(int j=i; j<n; j++) {
                current_min = 101;
                if(nums[j] > nums[i]) {
                    if(nums[j] <= current_min) {
                        current_min = nums[j];
                        i_swap = i;
                        j_swap = j;
                    }
                }
            }
        }
        if(i_swap  == 0 && j_swap == 0) {
            sort(nums.begin(), nums.end());
            return;
        }
        swap(nums[i_swap], nums[j_swap]);
        sort(nums.begin() + i_swap + 1, nums.end());
        
    }
};