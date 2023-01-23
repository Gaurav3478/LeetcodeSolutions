//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        for(int i = 0; i < n; i++) {
            //for each column for each row
            int knownTo = 0, knows = 0;
            for(int j = 0; j < n; j++) {
                if(j == i) {
                    continue;
                }
                knownTo += M[j][i];
            }
            for(int j = 0; j < n; j++) {
                if(j == i) {
                    continue;
                }
                knows += M[i][j];
            }
            
            if(knows == 0 && knownTo == n - 1) {
                return i;
            }
        }
        
        return -1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends