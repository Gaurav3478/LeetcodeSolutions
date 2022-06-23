vector<vector<int>> adj;
vector<bool> vis;
vector<int> ans;
vector<bool> helper;


void dfs(int v) {
    vis[v] = true;
    for(auto x: adj[v]) {
        if(!vis[x]) {
            dfs(x);
        }
    }
    ans.push_back(v);
}

bool checkCycle(int v) {
    vis[v] = true;
    helper[v] = true;
    for(auto it: adj[v]) {
        if(!vis[it]) {
            if(checkCycle(it)) {
                return true;
            }
        }
        else if(helper[it]) {
            return true;
        }
    }
    helper[v] = false;
    return false;
}

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //do topological sort
        //make edge from required course to potential course
        int n = numCourses;
        adj = vector<vector<int>>(n);
        int m = prerequisites.size();
        for(int i=0; i<m; i++) {
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            adj[b].push_back(a);
        }
        vis = vector<bool>(n, false);
        ans.clear();
        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                dfs(i);
            }
        }
        reverse(ans.begin(), ans.end());
        vis = vector<bool>(n, false);
        helper = vector<bool>(n, false);
        vector<int> v;
        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                if(checkCycle(i)) {
                    return v;
                }
            }
        }
        return ans;
    }
};