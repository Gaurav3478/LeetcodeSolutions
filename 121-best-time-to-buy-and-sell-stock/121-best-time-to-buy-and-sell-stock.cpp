class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minimum_so_far = prices[0];
        int ans = 0;
        for(int i=1; i<n; i++) {
            if(prices[i] < minimum_so_far) {
                minimum_so_far = prices[i];
            }
            ans = max(prices[i] - minimum_so_far, ans);
        }
        return ans;
    }
};