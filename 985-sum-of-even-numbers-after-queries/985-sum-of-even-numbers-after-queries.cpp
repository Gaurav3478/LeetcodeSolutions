class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++) {
            if(nums[i]%2 == 0) {
                sum += nums[i];
            }
        }
        int q = queries.size();
        vector<int> ans;
        int prev = -1;
        for(int qq=0; qq<q; qq++) {
            int val = queries[qq][0];
            int index = queries[qq][1];
            prev = nums[index];
            nums[index] += val;
            if(prev%2) {
                if(nums[index]%2 == 0) {
                    sum += nums[index];
                }
            }
            else {
                sum -= prev;
                if(nums[index]%2 == 0) {
                    sum += nums[index];
                }
            }
            ans.push_back(sum);
        }
        return ans;
    }
};