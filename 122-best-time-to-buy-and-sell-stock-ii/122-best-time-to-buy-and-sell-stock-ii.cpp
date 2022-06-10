class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int cur = prices[0];
        int maxSf = 0;
        int ans = 0;
        for(int i=1; i<n; i++) {
            if(prices[i] - cur < maxSf) {
                ans += maxSf;
                maxSf = 0;
                cur = prices[i];
            }
            else {
                maxSf = max(maxSf, prices[i] - cur);
            }
        }  
        ans += maxSf;
        return ans;
    }
};