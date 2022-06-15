class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxIdx = 0;
        //we want maxIdx to = n-1
        for(int i=0; i<n; i++) {
            if(maxIdx >= i) {
                maxIdx = max(maxIdx, i + nums[i]);
            }
        }
        return maxIdx >= n-1;
    }
};