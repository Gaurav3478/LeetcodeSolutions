class Solution {
public:
    const int MOD = 1e9 + 7;
    int numTilings(int n) {
        vector<long long> g(n+1, 0), u(n+1, 0);
        g[0] = u[0] = 0;
        g[1] = u[1] = 1;
        if(n >= 2) {
            g[2] = u[2] = 2;
        }
        for(int i=3; i<=n; i++) {
            u[i] = (u[i-1] + g[i-1])%MOD;
            g[i] = ((g[i-1] + g[i-2])%MOD + 2*u[i-2])%MOD;
        }
        return g[n];
    }
};