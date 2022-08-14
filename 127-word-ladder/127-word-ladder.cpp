class Solution {
public:
    int char_diff(string s1, string s2) {
        int cnt = 0;
        for(int i=0; i<s1.size(); i++) {
            if(s1[i] != s2[i]) {
                cnt++;
            }
        }
        return cnt;
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        q.push(beginWord);
        set<string> seen;
        seen.insert(beginWord);
        int ans = 1;
        int n = wordList.size();
        int len = beginWord.size();
        set<string> words(wordList.begin(), wordList.end());
        
        while(!q.empty()) {
            int sz = q.size();
            for(int i=0; i<sz; i++) {
                string cur_word = q.front();
                q.pop();
                
                if(cur_word == endWord) {
                    return ans;
                }
                
                for(int idx=0; idx<len; idx++) {
                    for(char c='a'; c<='z'; c++) {
                        string wrd = cur_word;
                        wrd[idx] = c;
                        if(words.find(wrd) != words.end() && seen.find(wrd) == seen.end()) {
                            q.push(wrd);
                            seen.insert(wrd);
                        }
                    }
                }
            }
            ans++;
        }
        
        return 0;
    }
};