class Solution {
public:
    int maxN = 5e4 + 1;
    int K = 25;
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        vector<vector<int>> sp(maxN, vector<int>(K + 1, 0));
        int n = chargeTimes.size();
        for(int i=0; i<n; i++) {
            sp[i][0] = chargeTimes[i];
        }
        for(int j=1; j<=K; j++) {
            for(int i=0; i + (1 << j) - 1 < n; i++) {
                sp[i][j] = max(sp[i][j-1], sp[i + (1 << (j - 1))][j - 1]);
            }
        }
        
        int lg[maxN+1];
        lg[1] = 0;
        for (int i = 2; i <= maxN; i++)
            lg[i] = lg[i/2] + 1;
        
        int i = 0, j = 0;
        long long int val = 0;
        int ans = 0;
        while(j < n) {
            val += runningCosts[j];
            int len = lg[j - i + 1];
            while((j - i + 1)*val + max(sp[i][len], sp[j - (1 << len) + 1][len]) > budget) {
                val -= runningCosts[i];
                i++;
                if(i >= j) {
                    break;
                }
                len = lg[j - i + 1];
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};