class Solution {
public:
    int ans = INT_MAX;
    int lastStoneWeightII(vector<int>& stones) {
        unordered_set<int> s = {0};
        for(int i = 0; i < stones.size(); ++i) {
            int n = stones[i];
            auto t = s;
            s = {};
            for(auto num : t) {
                s.insert(num + n);
                s.insert(num - n);
            }
        }
        for(auto n : s){
            ans = min(ans, abs(n));
        }
        
        return ans;
    }
};