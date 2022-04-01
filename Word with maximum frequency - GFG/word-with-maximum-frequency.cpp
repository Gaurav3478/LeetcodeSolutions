// { Driver Code Starts
#include <iostream>
#include <map>
#include <algorithm>
#include <sstream>
using namespace std;



string maximumFrequency(string s);

int main()
{
    int t;cin>>t;
    cin.ignore();

    for(int i=0;i<t;i++)
    {

        string s;
        getline(cin,s);
        
        
        cout << maximumFrequency(s) << endl;

    }
    return 0;
}
// } Driver Code Ends


string maximumFrequency(string s){
        // Complete the function
        string temp="";
       map<string, int> mp;
       string arr[100001];
       int ind=0;
       for(int i=0;i<s.size();i++){
           if(s[i]==' '){
               mp[temp]++;
               arr[ind++] = temp;
               temp="";
           }
           
           else temp+=s[i];
       }
       mp[temp]++;
       int max = 1;
       string res = arr[0];
       for(int i=0;i<ind;i++){
           if(max<mp[arr[i]]){
               res = arr[i];
               max = mp[arr[i]];
           }
       }
       string ans = res+" "+to_string(max);
       return ans;
        
}

