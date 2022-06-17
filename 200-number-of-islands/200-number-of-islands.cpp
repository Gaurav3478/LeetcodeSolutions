class Solution {
public:
    void dfs(vector<vector<char>> &grid, int row, int column) {
        if(row < 0 || column < 0 || row >= grid.size() || column >= grid[0].size()) {
            return;
        }
        if(grid[row][column] == '0') {
            return;
        }
        grid[row][column] = '0';
        dfs(grid, row, column + 1);
        dfs(grid, row, column - 1);
        dfs(grid, row + 1, column);
        dfs(grid, row - 1, column);
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == '1') {
                    dfs(grid, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};