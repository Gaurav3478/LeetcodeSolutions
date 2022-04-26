class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        if(n<4) {
            return ans;
        }
        sort(nums.begin(), nums.end());
        for(int i = 0; i<n-3; i++) {
            if(i>0&&nums[i]==nums[i-1]) continue;
            for(int j = i+1; j<n-2; j++) {
                if(j>i+1 && nums[j] == nums[j-1]) continue;
                int l = j + 1, r = n - 1;
                while(l < r) {
                    if(nums[i] + nums[j] > target - nums[l] - nums[r]) {
                        r--;
                    }
                    else if(nums[i] + nums[j] < target - nums[l] - nums[r]) {
                        l++;
                    }
                    else {
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        do{l++;} while(nums[l]==nums[l-1]&&l<r);
                        do{r--;}while(nums[r]==nums[r+1]&&l<r);
                    }
                }
            }
        }
        return ans;
    }
};