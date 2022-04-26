class Solution {
public:
    void solve(vector<vector<int>> &ans, vector<int> temp, int index, vector<int> nums) {
        if(index == nums.size()) {
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[index]);
        solve(ans, temp, index + 1, nums);
        int j = index;
        while(index < nums.size() && nums[j] == nums[index]) {
            index++;
        }
        index--;
        temp.pop_back();
        solve(ans, temp, index+1, nums);
    }        

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        solve(ans, temp, 0, nums);
        return ans;
    }
};