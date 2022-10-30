class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n = nums.size();
        map<int, vector<int>, greater<int>> mp;
        for(int i=0; i<n; i++) {
            mp[nums[i]].push_back(i);
        }
        
        vector<int> ans(n);
        set<int> seen_indexes;
        for(auto [i, vect]: mp) {
            for(auto j: vect) {
                auto it = seen_indexes.upper_bound(j);
                if(it != seen_indexes.end() && ++it != seen_indexes.end()) {
                    ans[j] = nums[*it];
                }
                else {
                    ans[j] = -1;
                }
            }
                
            for(auto j: vect) {
                seen_indexes.insert(j);
            }
        }
        
        return ans;
    }
};