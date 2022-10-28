class Solution {
public:
    string countingSort(string s) {
        vector<int> cnt(26, 0);
        for(char c: s) {
            cnt[c - 'a']++;
        }
        string t = "";
        for(int i=0; i<26; i++) {
            t += string(cnt[i], i + 'a');
        }
        return t;
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        map<string, vector<string>> mp;
        for(int i=0; i<n; i++) {
            string cur_str = strs[i];
            string sorted_str = countingSort(cur_str);
            mp[sorted_str].push_back(cur_str);
        }
        
        vector<vector<string>> anagrams;
        for(auto it: mp) {
            anagrams.push_back(it.second);
        } 
        
        return anagrams;
    }
};