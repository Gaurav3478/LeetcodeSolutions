// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

bool cmp(pair<Item, double> p1, pair<Item, double> p2) {
    return p1.second > p2.second;
}

class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        vector<pair<Item, double>> vect(n);
        for(int i=0; i<n; i++) {
            vect[i] = {arr[i], (double)arr[i].value/arr[i].weight};
        }
        sort(vect.begin(), vect.end(), cmp);
        double value = 0;
        int weight_so_far = 0;
        for(int i=0; i<n; i++) {
            if(weight_so_far >= W) {
                break;
            }
            if(weight_so_far + vect[i].first.weight <= W) {
                weight_so_far += vect[i].first.weight;
                value += vect[i].first.value;
            }
            else {
                //this is where my vector.second comes into play
                value += vect[i].second*(W-weight_so_far);
                break;
            }
        }
        return value;
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends