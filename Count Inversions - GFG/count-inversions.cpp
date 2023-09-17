//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long merge(int l, int mid, int r, long long arr[], long long temp[]) {
        int i = l, j = mid + 1;
        int start = l, end = r;
        long long inv = 0;
        int ptr = l;
        while(i <= mid && j <= r) {
            if(arr[i] <= arr[j]) {
                temp[ptr++] = arr[i++];
            }
            else {
                temp[ptr++] = arr[j++];
                inv += (mid - i + 1);
            }
        }
        
        while(i <= mid) {
            temp[ptr++] = arr[i++];
        }
        while(j <= r) {
            temp[ptr++] = arr[j++];
        }
        
        for(int x = start; x <= end; x++) {
            arr[x] = temp[x];
        }
        return inv;
    }
    
    long long findInversions(int l, int r, long long arr[], long long temp[]) {
        if(l == r) {
            return 0;
        }
        long long inversions = 0;
        int mid = (l + r) / 2;
        inversions += findInversions(l, mid, arr, temp);
        inversions += findInversions(mid + 1, r, arr, temp);
        inversions += merge(l, mid, r, arr, temp);
        // cout << l << ' ' << mid << ' ' << r << ' ' << inversions << endl;
        return inversions;
    }
    
    long long int inversionCount(long long arr[], long long n)
    {
        // Your Code Here
        long long temp[n];
        return findInversions(0, n - 1, arr, temp);
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends