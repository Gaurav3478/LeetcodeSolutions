class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        int n = words.size();
        int len = pattern.size();
        vector<string> ans;
        for(string word: words) {
            if(word.size() != len) {
                continue;
            }
            map<char, char> mp;
            set<char> taken; //represents letters in word that are taken
            bool ok = true;
            for(int i=0; i<len; i++) {
                if(mp.find(pattern[i]) == mp.end()) {
                    if(taken.find(word[i]) != taken.end()) {
                        ok = false;
                        break;
                    }
                    else {
                        mp[pattern[i]] = word[i];
                        taken.insert(word[i]);
                    }
                }
                else {
                    if(mp[pattern[i]] != word[i]) {
                        ok = false;
                        break;
                    }
                }
            }
            if(ok) {
                ans.push_back(word);
            }
        }
        return ans;
    }
};