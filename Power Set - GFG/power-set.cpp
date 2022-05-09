// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
		void solve(string s, vector<string> &ans, int index, string temp, int n) {
    //at each point we can either take or not take the string
    if(index == n) {
        if(temp.size() > 0) {
            ans.push_back(temp);
        }
        return;
    }
    //first option: take the character
    temp.push_back(s[index]);
    solve(s, ans, index+1, temp, n);
    //second option: don't take the character
    temp.pop_back();
    solve(s, ans, index+1, temp, n);
}

vector<string> AllPossibleStrings(string s){
    //ye kya dogalapan hai
    //we want to use recursion
    vector<string> ans;
    string temp;
    int n = s.size();
    solve(s, ans, 0, temp, n);
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