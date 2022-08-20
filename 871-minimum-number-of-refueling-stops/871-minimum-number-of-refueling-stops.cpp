class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        
        vector<long long int> dp(n + 1, 0);
        dp[0] = startFuel;
        for(int i=0; i<n; i++) {
            for (int j = i + 1; j > 0 && dp[j - 1] >= stations[i][0]; j--) {
                dp[j] = max(dp[j], dp[j - 1] + stations[i][1]);
            }
        }
        
        for(int i=0; i<=n; i++) {
            if(dp[i] >= target) {
                return i;
            }
        }
        return -1;
    }
};