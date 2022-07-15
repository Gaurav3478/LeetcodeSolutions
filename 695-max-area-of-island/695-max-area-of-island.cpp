class Solution {
public:
    bool isValid(int i, int j, int n, int m) {
        if(min(i, j) < 0 || i >= n || j >= m) {
            return false;
        }
        return true;
    }
    
    void dfs(int i, int j, int &cnt, vector<vector<int>> &grid, vector<vector<bool>> &vis) {
        if(isValid(i, j, grid.size(), grid[0].size()) && !vis[i][j]) {
            vis[i][j] = true;
            if(grid[i][j] == 1) {
                cnt++;
                dfs(i + 1, j, cnt, grid, vis);
                dfs(i -1, j, cnt, grid, vis);
                dfs(i, j+1, cnt, grid, vis);
                dfs(i, j-1, cnt, grid, vis);
            }
        }    
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        //do a dfs from each island
        int ans = 0;
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!vis[i][j] && grid[i][j] == 1) {
                    int cnt = 0;
                    dfs(i, j, cnt, grid, vis);
                    ans = max(ans, cnt);
                }
            }
        }
        return ans;
    }
};