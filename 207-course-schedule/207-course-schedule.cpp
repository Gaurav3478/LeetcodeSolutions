vector<vector<int>> adj;
vector<int> indegree;

class Solution {
public:
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
        for(int i=0; i<n; i++) {
            for(auto it: adj[i]) {
                indegree[it]++;
            }
        }
        queue<int> Q;
        for(int i=0; i<n; i++) {
            if(indegree[i] == 0) {
                Q.push(i);
            }
        }
        if(Q.empty()) {
            return false;
        }
        int cnt = 0;
        while(!Q.empty()) {
            int node = Q.front();
            Q.pop();
            cnt++;
            for(auto it: adj[node]) {
                indegree[it]--;
                if(indegree[it] == 0) {
                    Q.push(it);
                }
            }
        }
        if(cnt == n) {
            return true;
        }
        return false;
    }
};