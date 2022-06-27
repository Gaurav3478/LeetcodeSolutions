class Solution {
public:
    bool check(vector<vector<char>> &board, int i, int j, char c) {
        int squareRow = i - i%3, squareColumn = j - j%3;
        //checking all rows
        for(int k=0; k<9; k++) {
            if(board[k][j] == c) {
                return false;
            }
        }
        //checking all columns
        for(int k=0; k<9; k++) {
            if(board[i][k] == c) {
                return false;
            }
        }
        //checking the square
        for(int x=0; x<3; x++) {
            for(int y=0; y<3; y++) {
                if(board[squareRow+x][squareColumn+y] == c) {
                    return false;
                }
            }
        }
        return true;
    }
    
    bool solve(vector<vector<char>> &board, int i, int j) {
        if(i == 9) {
            return true;
        }
        if(j == 9) {
            return solve(board, i+1, 0);
        }
        if(board[i][j] != '.') {
            return solve(board, i, j + 1);
        }
        for(char c = '1'; c <= '9'; c++) {
            if(check(board, i, j, c)) {
                board[i][j] = c;
                if(solve(board, i, j+1)) {
                    return true;
                }
                board[i][j] = '.';
            }
        }
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board,0,0);
    }
};