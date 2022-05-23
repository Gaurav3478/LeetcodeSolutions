class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int maj = 0;
        int cnt = 0;
        for(int i=0; i<n; i++) {
            if(cnt == 0) {
                maj = nums[i];
                cnt++;
            } 
            else {
                if(nums[i] == maj) {
                    cnt++;
                }
                else {
                    cnt--;
                }
            }
        }
        return maj;
    }
};