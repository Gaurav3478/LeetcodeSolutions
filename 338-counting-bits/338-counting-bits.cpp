class Solution {
public:
    void solve(vector<int> &ans, int n) {
        int count = 0;
        while(n) {
            count++;
            n &= n-1;
        }
        ans.push_back(count);
    }

    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0; i<=n; i++) {
            solve(ans, i);
        }
        return ans;
    }
};