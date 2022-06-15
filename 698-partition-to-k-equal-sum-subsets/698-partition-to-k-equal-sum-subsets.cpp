class Solution {
public:
    bool recurse(vector<int> &nums, vector<bool> &visited, int target, int curr_sum, int i, int k) {
        if(k == 1) {
            return true;
        }
        if(i >= nums.size()) {
            return false;
        }
        if(curr_sum == target) {
            return recurse(nums, visited, target, 0, 0, k-1);
        }
        for(int j=i; j<nums.size(); j++) {
            if(visited[j] || curr_sum + nums[j] > target) {
                continue;
            }
            visited[j] = true;
            if(recurse(nums, visited, target, curr_sum + nums[j], j+1, k)) {
                return true;
            }
            visited[j] = false;
        }
        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        //recursive code (backtrack)
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++) {
            sum += nums[i];
        }
        if(sum%k) {
            return false;
        }
        sum = sum/k;
        sort(nums.begin(), nums.end(), greater<int>());
        vector<bool>visited(nums.size(), false);
        return recurse(nums, visited, sum, 0, 0, k);
    }
};