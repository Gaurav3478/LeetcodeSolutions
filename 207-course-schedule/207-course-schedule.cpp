vector<vector<int>> adj;
vector<int> indegree;
vector<bool> vis;
vector<bool> helper;

class Solution {
public:
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
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //check for cycle
        int n = numCourses;
        adj = vector<vector<int>>(n);
        indegree = vector<int>(n, 0);
        for(auto p: prerequisites) {
            int a = p[0];
            int b = p[1];
            adj[b].push_back(a);
        }
        vis = vector<bool>(n, false);
        helper = vector<bool>(n, false);
        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                if(checkCycle(i)) {
                    return false;
                }
            }
        }
        return true;
        
    }
};