class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, vector<int>> mp;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            mp[nums[i]].push_back(i);
        }
        for(auto it: mp) {
            int sz = it.second.size();
            for(int j=1; j<sz; j++) {
                if(mp[it.first][j] - mp[it.first][j - 1] <= k) {
                    return true;
                }
            }
        }
        return false;
    }
};