class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int n = words1.size(), m = words2.size();
        map<char, int> ref;
        for(int i=0; i<m; i++) {
            map<char, int> temp;
            for(int j=0; j<words2[i].size(); j++) {
                temp[words2[i][j]]++;
            }
            for(auto val: temp) {
                if(ref.find(val.first) == ref.end()) {
                    ref[val.first] = val.second;
                }
                else {
                    ref[val.first] = max(ref[val.first], val.second);
                }
            }
        }
        vector<string> ans;
        for(int i=0; i<n; i++) {
            map<char, int> mp;
            for(int j=0; j<words1[i].size(); j++) {
                mp[words1[i][j]]++;
            }
            bool ok = true;
            for(auto letter: ref) {
                char c = letter.first;
                int v = letter.second;
                if(mp.find(c) == mp.end()) {
                    ok = false;
                    break;
                }
                if(mp[c] < v) {
                    ok = false;
                    break;
                }
            }
            if(ok) {
                ans.push_back(words1[i]);
            }
        }
        return ans;
    }
};