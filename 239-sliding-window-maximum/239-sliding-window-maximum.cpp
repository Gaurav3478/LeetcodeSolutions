class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> ms;
        vector<int> ans;
        for(int i=0; i<k; i++) {
            ms.insert(nums[i]);
        }
        auto it = ms.end();
        ans.push_back(*--ms.end());
        for(int i=k; i<nums.size(); i++) {
            ms.erase(ms.find(nums[i-k]));
            ms.insert(nums[i]);
            ans.push_back(*--ms.end());
        }
        return ans;
    }
};