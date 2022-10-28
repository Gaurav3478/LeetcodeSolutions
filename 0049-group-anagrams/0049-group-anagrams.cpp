class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        int n = strs.size();
        map<string, vector<string>> mp;
        for(int i=0; i<n; i++) {
            string cur_str = strs[i];
            string cpy = cur_str;
            sort(cpy.begin(), cpy.end());
            mp[cpy].push_back(cur_str);
        }
        
        
        for(auto it: mp) {
            vector<string> temp;
            for(auto ele: it.second) {
                temp.push_back(ele);
            }
            ans.push_back(temp);
        } 
        
        return ans;
    }
};