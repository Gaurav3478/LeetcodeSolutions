class Solution {
public:
    void solve(vector<vector<int>> &ans, int index, vector<int> &nums, int n) {
        if(index == n) {
            ans.push_back(nums);
            return;
        }
        unordered_map<int, int> mp;
        for(int i=index; i<n; i++) {
            if(mp.count(nums[i]) == 1) {
                continue;
            }
            mp[nums[i]]++;
            swap(nums[index], nums[i]);
            solve(ans, index+1, nums, n);
            swap(nums[index], nums[i]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp = nums;
        int n = nums.size();
        solve(ans, 0, temp, n);
        return ans;
    }
};