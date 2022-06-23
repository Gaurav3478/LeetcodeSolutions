class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        int sz = edges.size();
        vector<vector<int>> adj(n);
        vector<int> inDegree(n, 0);
        if(n == 0) {
            return {};
        }
        else if(n == 1) {
            return {0};
        }
        for(int i=0; i<sz; i++) {
            int a = edges[i][0];
            int b = edges[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
            inDegree[a]++;
            inDegree[b]++;
        }
        //we want to do a BFS from the leaves
        //the leaf node will have an indegree of 1
        queue<int> Q;
        for(int i=0; i<n; i++) {
            if(inDegree[i] == 1) {
                Q.push(i);
            }
        }
        vector<int> ans;
        while(!Q.empty()) {
            ans.clear();
            int size = Q.size();
            for(int i=0; i<size; i++) {
                int node = Q.front();
                Q.pop();
                ans.push_back(node);
                for(auto x: adj[node]) {
                    inDegree[x]--;
                    if(inDegree[x] == 1) {
                        //it is now a leaf
                        Q.push(x);
                    }
                }
            }
        }
        return ans;
    }
};