//using no extra space (swapping)

class Solution {
public:
    void solve(int index, vector<vector<int>> &ans, vector<int> nums, int n) {
        if(index == n) {
            ans.push_back(nums);
            return;
        }
        for(int i = index; i<n; i++) {
            swap(nums[index], nums[i]);
            solve(index + 1, ans, nums, n);
            swap(nums[index], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        solve(0, ans, nums, n);
        return ans;
    }
};