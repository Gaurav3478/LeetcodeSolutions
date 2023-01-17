//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cutRod(int price[], int n) {
        //code here
        int dp[n + 1][n + 1];
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= n; i++) {
            int profit = price[i - 1];
            //i is the length of this rod
            for(int size = 1; size <= n; size++) {
                dp[i][size] = dp[i - 1][size];
                if(size - i >= 0) {
                    dp[i][size] = max(dp[i][size], dp[i][size - i] + profit);
                }
            }
        }
         
        return dp[n][n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends