class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int n = nums.size();
        int cnt;
        string str;
        set<string> s;
        for(int i = 0; i<n; i++) {
            cnt = 0;
            str = "";
            for(int j=i; j<n; j++) {
                str+=nums[j];
                if(nums[j]%p == 0) {
                    cnt++;
                }
                if(cnt <= k) {
                    s.insert(str);
                }
            }
        }
        return s.size();
    }
};