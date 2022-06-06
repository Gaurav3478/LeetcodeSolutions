class Solution {
public:
    void solve(vector<string> &ans, int index, string s, string digits, int n, map<int, string> mapping) {
        if(index == n) {
            ans.push_back(s);
            return;
        }
        int cur_digit = digits[index] - '0';
        for(auto num: mapping[cur_digit]) {
            s += num;
            solve(ans, index + 1, s, digits, n, mapping);
            s.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits == "") {
            return ans;
        } 
        int n = digits.size();
        map<int, string> mapping;
        mapping[2] = "abc";
        mapping[3] = "def";
        mapping[4] = "ghi";
        mapping[5] = "jkl";
        mapping[6] = "mno";
        mapping[7] = "pqrs";
        mapping[8] = "tuv";
        mapping[9] = "wxyz";
        solve(ans, 0, "", digits, n, mapping);
        return ans;     
    }
};