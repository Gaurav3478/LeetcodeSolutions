//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    
    bool check(int a[],int n, int m, int mid){
        int used=1;
        int pages=0;
        for(int i=0;i<n;i++){
            pages+=a[i];
            if(pages>mid){
                pages=a[i];
                used++;
            }
            if(used>m)
            return false;
        }
        return true;
    }
    
    int findPages(int a[], int n, int m) 
    {   
        
        int s=0,ans=0;
        int e=0;
        if(m > n) {
            return -1;
        }
        for(int i=0;i<n;i++){
            e+=a[i];
            s=max(s,a[i]);
        }
        while(s<=e){
            int mid=(s+e)/2;
            if(check(a,n,m,mid)){
                ans=mid;
                e=mid-1;
            }
            else
            s=mid+1;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends