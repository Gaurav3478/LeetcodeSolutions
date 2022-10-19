class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> freq;
        int n = words.size();
        for(int i=0; i<n; i++) {
            freq[words[i]]++;
        }
        
        auto cmp = [](pair<int, string> a, pair<int, string> b) {
            if(a.first == b.first) {
                return a.second < b.second;
            }
            return a.first > b.first;
        };
        
        set<pair<int, string>, decltype(cmp)> s(cmp);
        for(auto ele: freq) {
            s.insert({ele.second, ele.first});
        }
        
        while(s.size() > k) {
            auto it = s.end();
            it--;
            s.erase(it);
        }
        
        vector<string> ans;
        for(auto it: s) {
            ans.push_back(it.second);
        }
        
        return ans;
    }
};