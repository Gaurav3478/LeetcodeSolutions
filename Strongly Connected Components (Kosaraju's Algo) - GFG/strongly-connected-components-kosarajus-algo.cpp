//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	vector<int> order;
	void dfs(int v, vector<bool> & vis, vector<vector<int>> &adj) {
	    vis[v] = true;
	    for(auto ch: adj[v]) {
	        if(!vis[ch]) {
	            dfs(ch, vis, adj);
	        }
	    }
	    
	    order.push_back(v);
	}
	
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        order.clear();
        vector<bool> vis(V, false);
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                dfs(i, vis, adj);
            }
        }
        
        vector<vector<int>> reverse_adj(V);
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < (int)adj[i].size(); j++) {
                reverse_adj[adj[i][j]].push_back(i);
            }
        }
        
        reverse(order.begin(), order.end());
            
        vis.clear();
        vis.resize(V, false);
        int sccs = 0;
        for(int i = 0; i < V; i++) {
            int node = order[i];
            if(vis[node]) {
                continue;
            }
            sccs++;
            dfs(node, vis, reverse_adj);
        }
        return sccs;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends