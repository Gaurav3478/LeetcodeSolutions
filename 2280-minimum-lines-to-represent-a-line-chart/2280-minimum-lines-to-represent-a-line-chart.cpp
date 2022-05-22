class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) {
      int n = stockPrices.size();
      if(n==1) {
        return 0;
      }
      sort(stockPrices.begin(), stockPrices.end());
      int ans = 1;
      long double prevGrad = (long double)(stockPrices[1][1] - stockPrices[0][1])/(stockPrices[1][0] - stockPrices[0][0]);
      for(int i=1; i<n-1; i++) {
        long double curGrad = (long double)(stockPrices[i+1][1] - stockPrices[i][1])/(stockPrices[i+1][0] - stockPrices[i][0]);
        if(prevGrad != curGrad) {
          ans++;
        }
        prevGrad = curGrad;
      }
      return ans;
    }
};