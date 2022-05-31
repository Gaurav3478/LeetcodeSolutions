class Solution {
public:
    vector<vector<bool>> vis;
    
    bool searchWord(int i, int j, int index, vector<vector<char>> &board, string word) {
        if(index == word.size()) {
            return true;
        }
        if(i < 0 || i >=board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[index] || vis[i][j]) {
            return false;
        }
        vis[i][j] = true;
        if(searchWord(i+1, j, index+1, board, word) || 
           searchWord(i-1, j, index+1, board, word) || 
           searchWord(i, j + 1, index+1, board, word) || 
           searchWord(i, j-1, index+1, board, word)) {
            return true;
        }
        vis[i][j] = false;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vis.resize(n, vector<bool>(m, false));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(board[i][j] == word[0]) {
                    if(searchWord(i, j, 0, board, word)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};