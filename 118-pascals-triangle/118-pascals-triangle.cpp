class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        ans[0].push_back(1);
        int cur_max = 2;
        for(int i=1; i<numRows; i++) {
           for(int j=0; j<cur_max; j++) {
               if(j==0 || j==cur_max-1) {
                   ans[i].push_back(1);
               }
               else {
                   ans[i].push_back(ans[i-1][j-1] + ans[i-1][j]);
               }
           } 
            cur_max++;
        }
        return ans;
    }
};