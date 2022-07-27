class Solution {
public:
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; 
    
    bool isValid(int i, int j, int n) {
        if(min(i, j) < 0 || max(i, j) >= n) {
            return false;
        }
        return true;
    }
    
    void dfs(int i, int j, int n, int &sum, vector<vector<int>> &id, int cur_id, vector<vector<bool>> &vis, vector<vector<int>>& grid) {
        if(isValid(i, j, n) && !vis[i][j] && grid[i][j] == 1) {
            vis[i][j] = true;
            id[i][j] = cur_id;
            sum++;
            dfs(i, j+1, n, sum, id, cur_id, vis, grid);
            dfs(i, j-1, n, sum, id, cur_id, vis, grid);
            dfs(i+1, j, n, sum, id, cur_id, vis, grid);
            dfs(i-1, j, n, sum, id, cur_id, vis, grid);
        }
    }   
    
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        vector<vector<int>> id(n, vector<int>(n, -1));
        vector<int> islandSize;
        int cur_id = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1 && !vis[i][j]) {
                    int sum = 0;
                    dfs(i, j, n, sum, id, cur_id, vis, grid);
                    islandSize.push_back(sum);
                    cur_id++;
                }
            }
        }
        int ans = 0;
        for(int i=0; i<islandSize.size(); i++) {
            ans = max(ans, islandSize[i]);
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] != 0) {
                    continue;
                }
                set<int> s;
                int val = 0;
                for(auto dir: directions) {
                    int ni = i + dir.first;
                    int nj = j + dir.second;
                    if(isValid(ni, nj, n) && grid[ni][nj] == 1) {
                        int cur_id = id[ni][nj];
                        if(s.find(cur_id) == s.end()) {
                            val += islandSize[cur_id];
                            s.insert(cur_id);
                        }
                    }
                }
                val++;
                ans = max(ans, val);
            }
        }
        return ans;
    }
};