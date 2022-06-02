class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        //try using bitmask
        int n = nums.size();
        //=> 2^n subsets
        vector<vector<int>> ans;
        for(int i=0; i<1<<n; i++) {
            //i is my bitmask 
            vector<int> temp;
            for(int j=0; j<n; j++) {
                if(i & 1<<j) {
                    temp.push_back(nums[j]);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};