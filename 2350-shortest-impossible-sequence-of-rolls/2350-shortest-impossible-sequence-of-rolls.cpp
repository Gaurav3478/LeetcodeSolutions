class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        int ans = 0;
        map<int, int> mp;
        int cnt = 0;
        for(auto roll: rolls) {
            mp[roll]++;
            if(mp[roll] == 1) {
                cnt++;
                if(cnt%k == 0) {
                    ans++;
                    mp.clear();
                }
            }
        }
        return ans + 1;
    }
};