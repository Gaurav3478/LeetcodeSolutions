class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        set<int> s;
        s.insert(0);
        int ps = 0, ans = 0;
        for(int a: nums) {
            ps += a;
            if(s.find(ps - target) != s.end()) {
                ans++;
                s.clear();
            }
            s.insert(ps);
        }
        return ans;
    }
};