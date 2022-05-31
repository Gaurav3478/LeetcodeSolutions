class Solution {
public:
    void solve(vector<string> &ans, string cur, int open, int close, int max) {
        if(cur.size() == 2*max) {
            ans.push_back(cur);
            return;
        }
        if(open < max) {
            solve(ans, cur + "(", open + 1, close, max);
        }
        if(close < open) {
            solve(ans, cur + ")", open, close + 1, max);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(ans, "", 0, 0, n);
        return ans;
    }
};