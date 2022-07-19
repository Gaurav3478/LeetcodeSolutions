class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        ans[0] = {1};
        for(int i=1; i<numRows; i++) {
            ans[i].resize(i + 1);
            for(int j=0; j<i+1; j++) {
                int l = 0;
                if(j > 0) {
                    l = ans[i-1][j-1];
                }
                int r = 0;
                if(j < i) {
                    r = ans[i-1][j];
                }
                ans[i][j] = l + r;
            }
        }
        return ans;
    }
};