//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
     int solve(vector<int> &height,int n, int k){
        int dp[n];
        memset(dp,-1,sizeof(dp));
        dp[0]=0;
        
        
        for(int j=1;j<n;j++){
            int ans=INT_MAX;
        for(int i=1;i<=k;i++){
            
            if(j>=i){
             int temp= dp[j-i]+abs(height[j]-height[j-i]);
            ans=min(ans,temp);
            }
            
        }
        dp[j]=ans;
        }
        
        return dp[n-1];
    }
    int minimizeCost(vector<int>& height, int n, int k) {

        
        
        return solve(height,n,k);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends