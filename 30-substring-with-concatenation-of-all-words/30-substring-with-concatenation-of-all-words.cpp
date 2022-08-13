class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        map<string, int> mp;
        int n = s.size(), sz = words.size(), len = words[0].size();
        for(string &word: words) {
            mp[word]++;
        }
        
        vector<int> ans;
        for(int i=0; i<=n-len*sz; i++) {
            map<string, int> req = mp;
            bool ok = true;
            int cnt = 0;
            for(int j=i; j<=i+(sz-1)*len; j+=len) {
                string cur_word = s.substr(j, len);
                if(req.find(cur_word) != req.end()) {
                    req[cur_word]--;
                    if(req[cur_word] >= 0) {
                        cnt++;
                    }
                }
                else {
                    ok = false;
                    break;
                }
            }
            if(cnt == sz && ok) {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};