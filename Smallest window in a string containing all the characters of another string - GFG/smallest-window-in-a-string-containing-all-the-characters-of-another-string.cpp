// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
        int n = s.size(), v = p.size();
        //need to use sliding window technique
        map<char, int> m;
        int ans = INT_MAX; // length of ans
        int start = -1; // starting index of ans
        int count = 0;
        for (int i = 0; i <v; i++) {
            if (m[p[i]] == 0)
                count++;
            m[p[i]]++;
        }
        int i = 0, j = 0;
        while(j < n) {
            m[s[j]]--;
            if(m[s[j]] == 0) {
                count--;
            }
            if(count == 0) {
                while(count == 0) {
                    if(j - i + 1 < ans) {
                        ans = j - i + 1;
                        start = i;
                    }
                    m[s[i]]++;
                    if(m[s[i]] > 0) {
                        count++;
                    }
                    i++;
                }
            }
            j++;
        }
        if (start == -1)
            return "-1";
        else
            return s.substr(start, ans);
    }
};

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends