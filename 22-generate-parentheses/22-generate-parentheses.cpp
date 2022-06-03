class Solution {
public:
    void solve(vector<string> &ans, string cur, int n, int open, int close) {
        if(cur.size() == 2*n) {
            ans.push_back(cur);
            return;
        }
        //we want to take the left bracket first followed by right bracket
        if(open < n) {
            solve(ans, cur + '(', n, open+1, close);
        }
        if(close < open) {
            solve(ans, cur + ')', n, open, close + 1);
        }

    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(ans, "", n, 0, 0);
        return ans;
    }
};