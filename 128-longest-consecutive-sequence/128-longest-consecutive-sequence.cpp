class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //use an external array and then loop through that array?
        unordered_set<int> s(nums.begin(), nums.end());
        int n = nums.size();
        if(n==0) {
            return 0;
        }
        int ans = 1;
        for(int i=0; i<n; i++) {
            int cur = nums[i];
            s.erase(cur);
            int prev = cur-1;
            int next = cur+1;
            while(s.find(prev) != s.end()) {
                s.erase(prev);
                prev--;
            }
            while(s.find(next) != s.end()) {
                s.erase(next);
                next++;
            }
            ans = max(ans, next - prev - 1);
        }
        return ans;

    }
};