class Solution {
public:
    void dfs(vector<vector<int>> &heights, int row, int column, vector<vector<int>> &ocean, int prev) {
        if(row < 0 || column < 0 || row >= heights.size() || column >= heights[0].size()) {
            return;
        }
        if(ocean[row][column] == 1) {
            return;
        }
        if(heights[row][column] < prev) {
            return;
        }
        ocean[row][column] = 1;
        dfs(heights, row, column + 1, ocean, heights[row][column]);
        dfs(heights, row, column - 1, ocean, heights[row][column]);
        dfs(heights, row + 1, column, ocean, heights[row][column]);
        dfs(heights, row - 1, column, ocean, heights[row][column]);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> pacific(n, vector<int>(m, 0)), atlantic(n, vector<int>(m, 0));
        for(int i=0; i<m; i++) {
            dfs(heights, 0, i, pacific, INT_MIN);
            dfs(heights, n-1, i, atlantic, INT_MIN);
        }
        for(int i=0; i<n; i++) {
            dfs(heights, i, 0, pacific, INT_MIN);
            dfs(heights, i, m-1, atlantic, INT_MIN);
        }
        vector<vector<int>> ans;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(pacific[i][j] && atlantic[i][j]) {
                    vector<int> temp;
                    temp.push_back(i);
                    temp.push_back(j);
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }
};