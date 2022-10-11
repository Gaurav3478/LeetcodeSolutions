class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefMin(n + 1, 1e9 + 5), suffMax(n + 1, -1);
        for(int i=0; i<n; i++) {
            prefMin[i + 1] = min(prefMin[i], nums[i]);
        }
        for(int i=n-1; i>=0; i--) {
            suffMax[i] = max(suffMax[i + 1], nums[i]);
        }
        
        for(int i=1; i<n-1; i++) {
            if(nums[i] > prefMin[i] && nums[i] < suffMax[i + 1]) {
                return true;
            }
        }
        return false;
    }
};