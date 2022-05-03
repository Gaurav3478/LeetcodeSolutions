class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> copy = nums;
        if(n == 1) {
            return 0;
        }
        sort(copy.begin(), copy.end());
        int low = 1e9, high = 0;
        for(int i=0; i<n; i++) {
            if(nums[i] != copy[i]) {
                low = min(low, i);
                high = max(high, i);
            }
        }
        return high - low + 1 > 0?high-low+1:0;
    }
};