class Solution {
public:
    static bool cmp(pair<int, int> &a, pair<int, int> &b) {
        return a.second < b.second;
    }
    
    long long minimumMoney(vector<vector<int>>& transactions) {
        int n = transactions.size();
        vector<vector<int>> losses, profits;
        for(int i=0; i<n; i++) {
            if(transactions[i][0] - transactions[i][1] > 0) {
                losses.push_back({transactions[i][0], transactions[i][1]});
            }
            else {
                profits.push_back({transactions[i][0], transactions[i][1]});
            }
        }
        
        sort(losses.begin(), losses.end(), [&](auto &x, auto &y) {
            return x[1] < y[1];
        });
        sort(profits.begin(), profits.end(), [&](auto &x, auto &y) {
            return x[0] > y[0];
        });
        
        int m = losses.size();
        long long ans = 0, sum = 0;
        for(int i=0; i<m; i++) {
            ans = max(ans, losses[i][0] + sum);
            sum += losses[i][0] - losses[i][1];
        }
        int m2 = profits.size();
        for(int i=0; i<m2; i++) {
            ans = max(ans, profits[i][0] + sum);
            sum += profits[i][0] - profits[i][1];
        }
        
        return ans;
    }
};