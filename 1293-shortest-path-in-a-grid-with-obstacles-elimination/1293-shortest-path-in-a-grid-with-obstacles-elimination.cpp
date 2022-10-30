class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, -1));
        queue<vector<int>> Q;
        //row, column, length of path, best remaining k
        Q.push({0, 0, 0, k});
        while(!Q.empty()) {
            int r = Q.front()[0];
            int c = Q.front()[1];
            int pathLen = Q.front()[2];
            int remaining_k = Q.front()[3];
            Q.pop();
            
            if(r == n - 1 && c == m - 1) {
                return pathLen;
            }
            
            if(min(r, c) < 0 || r >= n || c >= m) {
                continue;
            }
            
            if(grid[r][c] == 1) {
                if(remaining_k >= 1) {
                    remaining_k--;
                }
                else {
                    continue;
                }
            }
            
            if(vis[r][c] != -1) {
                //this cell has been visited before
                if(remaining_k > vis[r][c]) {
                    vis[r][c] = remaining_k;
                }
                else {
                    continue;
                }
            }
            else {
                vis[r][c] = remaining_k;
            }
            
            Q.push({r + 1, c, pathLen + 1, remaining_k});
            Q.push({r, c + 1, pathLen + 1, remaining_k});
            Q.push({r - 1, c, pathLen + 1, remaining_k});
            Q.push({r, c - 1, pathLen + 1, remaining_k});
        }
        return -1;
    }
};