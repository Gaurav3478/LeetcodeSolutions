class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n);
        //dp[i][j] represents the minimum cost to get to that point
        for(int i=0; i<n; i++) {
            dp[i].clear();
            dp[i].resize(triangle[i].size());
            for(int j=0; j<triangle[i].size(); j++) {
                if(i==0 && j==0) {
                    dp[i][j] = triangle[i][j];
                }
                else if(j == triangle[i-1].size()) {
                    dp[i][j] = triangle[i][j] + dp[i-1][j-1];
                }
                else if(j == 0) {
                    dp[i][j] = triangle[i][j] + dp[i-1][j];
                }
                else {
                    dp[i][j] = triangle[i][j] + min(dp[i-1][j], dp[i-1][j-1]);
                }
            }
        }
        int ans = INT_MAX;
        for(int i=0; i<triangle[n-1].size(); i++) {
            ans = min(ans, dp[n-1][i]);
        }
        return ans;
    }
};