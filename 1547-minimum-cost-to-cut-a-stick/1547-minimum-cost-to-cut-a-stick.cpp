class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int sz = cuts.size();
        sort(cuts.begin(), cuts.end());
        vector<int> vect(sz + 2);
        vect[0] = 0;
        vect[sz+1] = n;
        for(int i=0; i<sz; i++) {
            vect[i+1] = cuts[i];
        }
        vector<vector<int>> dp(sz+2, vector<int>(sz+2, INT_MAX));
        sz += 2;
        for(int i=0; i<sz; i++) {
            for(int j=0; j<sz; j++) {
                if(j < i) {
                    dp[i][j] = 0;
                }
            }
        }
        for(int i=sz-2; i>=1; i--) {
            for(int j=1; j<=sz-2; j++) {
                for(int k=i; k<=j; k++) {
                    dp[i][j] = min(dp[i][j], vect[j+1] - vect[i-1] + dp[i][k-1] + 
                dp[k+1][j]);
                }
            }
        }
        return dp[1][sz-2];
    }
};