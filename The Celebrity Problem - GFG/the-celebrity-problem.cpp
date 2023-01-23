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
        int potentialRow = 0;
        for(int i = 1; i < n; i++) {
            if(M[potentialRow][i] == 1) {
                potentialRow = i;
            }
        }
        
        int knows = 0, knownTo = 0;
        for(int i = 0; i < n; i++) {
            if(i == potentialRow) {
                continue;
            }
            if(M[potentialRow][i] == 1) {
                knows++;
            }
        }
        
        for(int i = 0; i < n; i++) {
            if(i == potentialRow) {
                continue;
            }
            if(M[i][potentialRow] == 1) {
                knownTo++;
            }
        }
        
        if(knownTo == n - 1 && knows == 0) {
            return potentialRow;
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