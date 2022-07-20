class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        //literaly check if every string is a subsequence of s
        int n = s.size();
        map<char, vector<int>> mp;
        for(int i=0; i<n; i++) {
            mp[s[i]].push_back(i);
        }
        int ans = 0;
        for(int i=0; i<words.size(); i++) {
            string cur_word = words[i];
            int cur_index = -1;
            for(int j=0; j<cur_word.size(); j++) {
                char c = cur_word[j];
                auto it = upper_bound(mp[c].begin(), mp[c].end(), cur_index);
                if(it == mp[c].end()) {
                    break;
                }
                else {
                    if(j == cur_word.size() - 1) {
                        ans++;
                    }
                    else {
                        cur_index = *it;
                    }
                }
            }
        }
        return ans;
    }
};