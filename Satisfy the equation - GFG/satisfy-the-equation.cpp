//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> satisfyEqn(int A[], int N) {
        // code here
        map<int, pair<int, int>> mp;
        vector<int> ans = {INT_MAX, INT_MAX, INT_MAX, INT_MAX};

        for(int i=0; i<N; i++) {
            for(int j=i + 1; j<N; j++) {
                int sum = A[i] + A[j];
                if(mp.find(sum) == mp.end()) {
                    mp[sum] = {i, j};
                }
                else {
                    int a = mp[sum].first, b = mp[sum].second, c = i, d = j;
                    if(a != c && a != d && b != c && b != d) {
                        vector<int> cur = {a, b, c, d};
                        for(int k=0; k<4; k++) {
                            if(cur[k] < ans[k]) {
                                ans = {a, b, c, d};
                                break;
                            }
                            else if(ans[k] < cur[k]) {
                                break;
                            }
                        }  
                    }
                }
            }
        }
        
        if(ans[0] == INT_MAX) {
            ans = {-1, -1, -1, -1};
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        vector<int> ptr = ob.satisfyEqn(A,N);
        
        cout<<ptr[0]<<" "<<ptr[1]<<" "<<ptr[2]<<" "<<ptr[3]<<endl;
    }
    return 0;
}
// } Driver Code Ends