class Solution {
public:
    vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    
    bool isValid(int i, int j, int n, int m) {
        return min(i, j) >= 0 && i < n && j < m;
    }
    
    void dfs(int i, int j, int n, int m, vector<vector<int>> &image, vector<vector<bool>> &vis, int startColor, int color) {
        image[i][j] = color;
        vis[i][j] = true;
        for(auto dir: dirs) {
            int newi = i + dir.first;
            int newj = j + dir.second;
            if(isValid(newi, newj, n, m) && !vis[newi][newj] && image[newi][newj] == startColor) {
                dfs(newi, newj, n, m, image, vis, startColor, color);
            } 
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size(), m = image[0].size();
        int startColor = image[sr][sc];
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        dfs(sr, sc, n, m, image, vis, startColor, color);
        return image;
    }
};