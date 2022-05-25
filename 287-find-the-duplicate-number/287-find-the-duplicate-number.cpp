class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int duplicate;
        for(int i=0; i<n-1; i++) {
            if(nums[i] == nums[i+1]) {
                duplicate = nums[i];
                break;
            }
        }
        return duplicate;
    }
};