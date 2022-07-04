const int MOD = 1e9 + 7;
class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long int> dp(n, 0);
        //dp[i] represents the number of people who learn the secret on day i
        dp[0] = 1;
        long int totalSharers = 0;
        for(long int i=1; i<n; i++) {
            long int newShares = 0;
            long int forgets = 0;
            if(i - delay >= 0) {
                newShares = dp[i-delay];
            }
            if(i - forget >= 0) {
                forgets = dp[i-forget];
            }
            // cout << totalSharers << " " << newShares << " " << forgets << endl;
            dp[i] = (totalSharers%MOD - forgets%MOD + newShares%MOD + MOD)%MOD;
            totalSharers = (totalSharers%MOD - forgets%MOD + newShares%MOD + MOD)%MOD;
        }
        // cout << endl;
        // for(long int i=0; i<n; i++) {
        //     cout << dp[i] << " ";
        // }
        // cout << endl;
        long int ans = 0;
        for(int i=max(n-forget, 0); i<n; i++) {
            ans = (ans + dp[i])%MOD;
        }
        return ans;
    }
};