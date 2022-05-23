class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // int ans;
        // int len = nums.size();
        // int cnt1  = 0;
        // int current_maj = nums[0];
        // for(int i=0; i<len; i++) {
        //     nums[i] == current_maj? cnt1++:cnt1--;
        //     if(cnt1==0) {
        //         cnt1 = 1;
        //         current_maj = nums[i];
        //     }
        // }
        // return current_maj;
        map<int, int> mp;
        int len = nums.size();
        for(int i=0; i<len; i++) {
            mp[nums[i]]++;
        }
        int max = -1;
        int ans = 0;
        for(auto it: mp) {
            if(it.second>max) {
                max = it.second;
                ans = it.first;
            }
        }
        return ans;
        
    }
};