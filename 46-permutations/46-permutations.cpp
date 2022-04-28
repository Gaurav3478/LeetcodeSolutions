class Solution {
public:
    void solve(vector<vector<int>> &ans, int l, int r, vector<int> nums) {
        if(l == r) {
            ans.push_back(nums);
            return;
        }
        for (int i = l; i <= r; i++)
        {
 
            // Swapping done
            swap(nums[l], nums[i]);
 
            // Recursion called
            solve(ans, l+1, r, nums);
 
            //backtrack
            swap(nums[l], nums[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int l = 0, r = nums.size() - 1;
        solve(ans, l, r, nums);
        return ans;
    }
};