class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> ans(m);
        for(int col=0; col<m; col++) {
            int j = col;
            //we will traverse level by level
            bool trapped = false;
            for(int level = 0; level < n; level++) {
                if(j == 0 && grid[level][j] == -1) {
                    trapped = true;
                    break;
                }
                if(j == m - 1 && grid[level][j] == 1) {
                    trapped = true;
                    break;
                }
                if(j > 0 && (grid[level][j] == -1 && grid[level][j - 1] == 1)) {
                    trapped = true;
                    break;
                }
                if(j < m - 1 && (grid[level][j] == 1 && grid[level][j + 1] == -1)) {
                    trapped = true;
                    break;
                }
                j = (grid[level][j] == -1 ? j - 1 : j + 1); 
            }
            if(trapped) {
                ans[col] = -1;
            }
            else {
                ans[col] = j;
            }
        }
        
        return ans;
    }
};