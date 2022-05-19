class Solution {
public:
    int missingNumber(vector<int>& nums) {
        map<int, int> mp;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            mp[nums[i]]++;
        }
        int cur = 0;
        for(auto ele: mp) {
            if(ele.first != cur) {
                return cur;
            }
            cur++;
        }
        return n;
    }
};