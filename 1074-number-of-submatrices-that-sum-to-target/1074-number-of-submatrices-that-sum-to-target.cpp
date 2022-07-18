class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> pref(n, vector<int>(m, 0));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(j == 0) {
                    pref[i][j] = matrix[i][j];
                }
                else {
                    pref[i][j] = pref[i][j-1] + matrix[i][j];
                }
            }
        }
        int ans = 0;
        unordered_map<int, int> ump;
        for(int start=0; start<m; start++) {
            for(int end=start; end<m; end++) {
                int sum = 0;
                ump.clear();
                ump[0]++;
                for(int i=0; i<n; i++) {
                    int cur = pref[i][end];
                    if(start > 0) {
                        cur -= pref[i][start-1];
                    }
                    sum += cur;
                    ans += ump[sum - target];
                    ump[sum]++;
                }
            }
        }
        return ans;
    }
};