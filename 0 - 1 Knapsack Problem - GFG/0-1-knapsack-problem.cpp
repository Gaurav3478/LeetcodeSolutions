//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       int dp[n + 1][W + 1];
       memset(dp, 0, sizeof(dp));
       for(int i = 1; i <= n; i++) {
           int weight = wt[i - 1], value = val[i - 1];
           for(int j = 0; j <= W; j++) {
               dp[i][j] = dp[i - 1][j];
                if(j - weight >= 0) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - weight] + value);
                }
           }
       }
       
       return dp[n][W];
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends