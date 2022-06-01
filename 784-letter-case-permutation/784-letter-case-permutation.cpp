class Solution {
public:
    void solve(vector<string> &ans, int index, int n, string str, string s) {
        if(index == n) {
            ans.push_back(str);
            return;
        }
        if(s[index] >= 'a' && s[index] <= 'z' || s[index] >= 'A' && s[index] <= 'Z') {
            //it is a letter
            solve(ans, index+1, n, str + s[index], s);
            if(s[index] >= 'a' && s[index] <= 'z') {
                solve(ans, index+1, n, str+char(s[index]-32), s);
            }
            else {
                solve(ans, index+1, n, str+char(s[index]+32), s);
            }
        }
        else {
            // it is a digit
            solve(ans, index+1, n, str+s[index], s);
        }
    }

    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        int n = s.size();
        //for each letter, take lower and upper permutation
        solve(ans, 0, n, "", s);
        return ans;
    }
};