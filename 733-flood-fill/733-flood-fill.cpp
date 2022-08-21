class Solution {
public:
    vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    
    bool isValid(int i, int j, int n, int m) {
        return min(i, j) >= 0 && i < n && j < m;
    }
    
    void recurse(int i, int j, int n, int m, vector<vector<int>> &image, vector<vector<bool>> &vis, int startColor, int color) {
        if(isValid(i, j, n, m) && !vis[i][j]) {
            if(image[i][j] == startColor) {
                vis[i][j] = true;
                image[i][j] = color;
                for(auto dir: dirs) {
                    int newi = i + dir.first;
                    int newj = j + dir.second;
                    if(isValid(newi, newj, n, m)) {
                        recurse(newi, newj, n, m, image, vis, startColor, color);
                    } 
                }
            }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size(), m = image[0].size();
        int startColor = image[sr][sc];
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        recurse(sr, sc, n, m, image, vis, startColor, color);
        return image;
    }
};