class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> vect;
        for(int i=0; i<nums.size(); i++) {
            auto it = lower_bound(vect.begin(), vect.end(), nums[i]);
            if(it == vect.end()) {
                vect.push_back(nums[i]);
            }
            else {
                int idx = it - vect.begin();
                vect[idx] = nums[i];
            }
        }
        return vect.size();
    }
};