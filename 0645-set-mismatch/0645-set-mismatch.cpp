class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> ans;
        for(int i=1; i<n; i++) {
            if(nums[i] == nums[i - 1]) {
                ans.push_back(nums[i]);
            }
        }
        
        for(int num=1; num<=n; num++) {
            if(!binary_search(nums.begin(), nums.end(), num)) {
                ans.push_back(num);
            }
        }
        
        return ans;
    }
};