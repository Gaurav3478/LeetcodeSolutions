//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    pair<long long, long long> dfs(int v, int par, int N, vector<vector<int>> &adj, vector<int> &A, long long &ans) {
        bool entered = false;
        long long bestOdd = -1e18, bestEven = -1e18;
        for(auto x: adj[v]) {
            if(x != par) {
                entered = true;
                pair<long long, long long> p = dfs(x, v, N, adj, A, ans);
                bestEven = max(bestEven, A[v] + p.second);
                bestOdd = max(bestOdd, -A[v] + p.first);
            }
        }
        
        if(!entered) {
            ans = max(ans, (long long)A[v]);
            return {A[v], -A[v]};
        }   
        else {
            ans = max({ans, -bestOdd, bestEven});
            return {bestEven, bestOdd};
        }
    }   
  
    long long bestNode(int N, vector<int> &A, vector<int> &P) {
        // code here
        long long ans = -1e18;
        vector<vector<int>> adj(N);
        for(int i = 1; i < N; i++) {
            adj[i].push_back(P[i] - 1);
            adj[P[i] - 1].push_back(i);
        }
        dfs(0, -1, N, adj, A, ans);
        return ans;
    }
};

/*
2 5 6 3 4 1
if start from 2: 2 - 5 + 6 - 3 + 4 - 1 = 3
if don't start from 2: -2 + 5 - 6 + 3 -4 + 1 = -3
x => -x
at every node, we store 2 values: the best sum if this node is at an even index in the final permutation, 
and the best sum if this node is at an odd position in the final permutation
*/

//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        
        vector<int> P(N);
        Array::input(P,N);
        
        Solution obj;
        long long res = obj.bestNode(N, A, P);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends