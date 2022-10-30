class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, -1));
        queue<vector<int>> Q;
        //row, column, length of path, best remaining k
        Q.push({0, 0, 0, k});
        while(!Q.empty()) {
            auto t = Q.front();
            int r = t[0], c = t[1];
            Q.pop();
            
            if(min(r, c) < 0 || r >= n || c >= m) {
                continue;
            }
            
            if(r == n - 1 && c == m - 1) {
                return t[2];
            }
            
            if(grid[r][c] == 1) {
                if(t[3] >= 1) {
                    t[3]--;
                }
                else {
                    continue;
                }
            }
            
            if(vis[r][c] != -1 && vis[r][c] >= t[3]) {
                continue;
            }

            vis[r][c] = t[3];
            
            Q.push({r + 1, c, t[2] + 1, t[3]});
            Q.push({r - 1, c, t[2] + 1, t[3]});
            Q.push({r, c + 1, t[2] + 1, t[3]});
            Q.push({r, c - 1, t[2] + 1, t[3]});
        }
        return -1;
    }
};