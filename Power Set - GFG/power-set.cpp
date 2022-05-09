// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
            //bit manipulation
            vector<string> ans;
            int n = s.size();
            string sub;
            for(int num = 1; num < (1<<n); num++) {
                sub = "";
                for(int i=0; i<n; i++) {
                    if(num & (1<<i)) {
                        sub += s[i];
                    }
                }
                ans.push_back(sub);
            }
            sort(ans.begin(), ans.end());
            return ans;

        }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}  // } Driver Code Ends