class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m =  matrix[0].size();
        //first check if all starting points in j = 0 column work
        //then check if all starting points in i = 0 work
        //j == 0 and i == 0 overlap so only need to check that once
        
        bool ok = true;
        
        for(int i=n - 1; i >= 0; i--) {
            int cur = matrix[i][0];
            int ii = i, jj = 0;
            while(ii + 1 < n && jj + 1 < m) {
                if(matrix[ii + 1][jj + 1] != cur) {
                    ok = false;
                }
                ii++;
                jj++;
            }
        }
        
        for(int j = 1; j<m; j++) {
            int cur = matrix[0][j];
            int ii = 0, jj = j;
            while(ii + 1 < n && jj + 1 < m) {
                if(matrix[ii + 1][jj + 1] != cur) {
                    ok = false;
                }
                ii++;
                jj++;
            }
        }
        
        if(ok) {
            return true;
        }
        else {
            return false;
        }
    }
};