class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        // vector<vector<int>> dp(n, vector<int>(m, 0));
        vector<int> prev(m, 0), cur(m, 0);
        int ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(i == 0 && j == 0) {
                    cur[j] = (matrix[i][j] == '1');
                }
                else if(i == 0) {
                    cur[j] = (matrix[i][j] == '1');
                }
                else if(j == 0) {
                    cur[j] = (matrix[i][j] == '1');
                }
                else {
                    if(matrix[i][j] == '0') {
                        cur[j] = 0;
                    }
                    else {
                        cur[j] = 1 + min({prev[j-1], prev[j], cur[j-1]});
                    }
                }
                ans = max(ans, cur[j]);
            }
            prev = cur;
        }
        return ans*ans;
    }
};