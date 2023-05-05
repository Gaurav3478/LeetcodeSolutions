//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

int findEqualPoint(int arr[], int n) ;

int main()
{
	int t; cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n]={0};
		for(int i = 0; i < n; i++)
		cin>>arr[i];
		
		cout<< findEqualPoint(arr, n) <<endl;
	}
	
	return 0;
}

// } Driver Code Ends


int findEqualPoint(int arr[], int n) 
{
    // Your code goes here
    vector<pair<int, int>> newArr;
    for(int i = 0; i < n; i++) {
        if(i == 0 || arr[i] != arr[i - 1]) {
            newArr.push_back({arr[i], i});
        }
    }
    
    int sz = newArr.size();
    if(newArr.size() % 2 == 0) {
        return -1;
    }
    return newArr[sz / 2].second;
    return -1;
}