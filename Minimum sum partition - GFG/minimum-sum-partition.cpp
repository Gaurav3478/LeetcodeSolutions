//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int nums[], int n)  { 
	    // Your code goes here
	    int sum=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]<0)
            sum+=(-nums[i]);
            else
            sum+=nums[i];
        }

        vector<vector<bool>> dp(n+1,vector<bool>(sum+1,false));

        for(int i=0;i<=n;i++){
            for(int j=0;j<=sum;j++){
            if(i==0)
            dp[i][j]=false;
            if(j==0)
            dp[i][j]=true;
            }
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(abs(nums[i-1])<=j)
                dp[i][j]=dp[i-1][j-abs(nums[i-1])] or dp[i-1][j];
                else
                dp[i][j]=dp[i-1][j];
            }
        }

        

        int ans=sum;
        for(int i=sum/2;i>=0;i--){
            if(dp[n][i]==true){
                ans=sum-(2*i);
                break;
            }
        }

        return ans;
    
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends