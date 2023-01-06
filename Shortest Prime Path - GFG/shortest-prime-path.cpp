//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

/*
bfs
*/

class Solution{   
  public:
    int shortestPath(int Num1,int Num2)
    {   
        // Complete this function using prime vector
        const int N = 1e4;
        vector<bool> is_prime(N + 5, true);
        is_prime[0] = is_prime[1] = false;
        for (int i = 2; i <= N; i++) {
            if (is_prime[i] && (long long)i * i <= N) {
                for (int j = i * i; j <= N; j += i)
                    is_prime[j] = false;
            }
        }  
        
        if(Num1 > Num2) {
            swap(Num1, Num2);
        }
        
        const int INF = INT_MAX;
        vector<int> minOps(N, INF);
        minOps[Num1] = 0;
        queue<string> Q;
        string s = to_string(Num1);
        Q.push(s);
        while(!Q.empty()) {
            string s = Q.front();
            int num1 = stoi(s);
            Q.pop();
            for(int j = 3; j >= 0; j--) {
                for(char dig = '0'; dig <= '9'; dig++) {
                    if(j == 0 && dig =='0') {
                        continue;
                    }
                    if(dig == s[j]) {
                        continue;
                    }
                    string s2 = s;
                    s2[j] = dig;
                    int num = stoi(s2);
                    if(is_prime[num] && minOps[num] > minOps[num1] + 1) {
                        minOps[num] = minOps[num1] + 1;
                        Q.push(s2);
                    }
                }
            }
        }
        
        return minOps[Num2];
    }
};


//{ Driver Code Starts.
signed main()
{
    int t;
    cin>>t;
    Solution obj;
    while(t--)
    {
        int Num1,Num2;
        cin>>Num1>>Num2;
        int answer=obj.shortestPath(Num1,Num2);
        cout<<answer<<endl;
    }
}
// } Driver Code Ends