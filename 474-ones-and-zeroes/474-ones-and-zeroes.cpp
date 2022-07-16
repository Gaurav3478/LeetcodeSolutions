class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz = strs.size();
        vector<vector<vector<int>>> dp(sz, vector<vector<int>>(m+1, vector<int>(n + 1, 0)));
        //dp[index][zeroCnt][oneCnt]
        int oneCnt = 0, zeroCnt = 0;
        for(int i=0; i<strs[0].size(); i++) {
            oneCnt += strs[0][i] == '1';
            zeroCnt += strs[0][i] == '0';
        }
        for(int i=0; i<=m; i++) {
            for(int j=0; j<=n; j++) {
                if(i >= zeroCnt && j >= oneCnt) {
                    dp[0][i][j] = 1;
                }
            }
        }
        for(int i=1; i<sz; i++) {
            oneCnt = zeroCnt = 0;
            for(int l=0; l<strs[i].size(); l++) {
                oneCnt += strs[i][l] == '1';
                zeroCnt += strs[i][l] == '0';
            }
            for(int j=0; j<=m; j++) {
                for(int k=0; k<=n; k++) {
                    int donttake = dp[i-1][j][k];
                    int take = 0;
                    if(j - zeroCnt >= 0 && k - oneCnt >= 0) {
                        take = dp[i-1][j - zeroCnt][k - oneCnt] + 1;
                    }
                    dp[i][j][k] = max(take, donttake);
                }
            }            
        }
        // for(auto it: dp) {
        //     for(auto jt: it) {
        //         for(auto kt: jt) {
        //             cout << kt << " ";
        //         }
        //         cout << endl;
        //     }
        //     cout << endl;
        // }
        return dp[sz-1][m][n];
    }
};