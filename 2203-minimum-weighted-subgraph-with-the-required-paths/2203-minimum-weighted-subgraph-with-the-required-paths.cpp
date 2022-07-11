class Solution {
public:
    long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<vector<pair<long, long>>> adj(n), revadj(n);
        for(int i=0; i<edges.size(); i++) {
            long u = edges[i][0];
            long v = edges[i][1];
            long w = edges[i][2];
            adj[u].push_back({v, w});
            revadj[v].push_back({u, w});
        }
        auto dijkstra = [&](long s, vector<vector<pair<long, long>>> &adj, vector<long> &shortestPath) {
            priority_queue<pair<long, long>, vector<pair<long, long>>, greater<pair<long, long>>> pq;
            shortestPath[s] = 0;
            pq.push({0, s});
            while(!pq.empty()) {
                pair<long, long> p = pq.top();
                long cost = p.first;
                long node = p.second;
                pq.pop();
                if(cost > shortestPath[node]) {
                    continue;
                }
                for(auto &[v, curcost]: adj[node]) {
                    if(shortestPath[v] > shortestPath[node] + curcost) {
                        shortestPath[v] = shortestPath[node] + curcost;
                        pq.push({shortestPath[v], v});
                    }
                }
            }
        };
        vector<long> da(n, LLONG_MAX), db(n, LLONG_MAX), dc(n, LLONG_MAX);
        dijkstra(src1, adj, da);
        dijkstra(src2, adj, db);
        dijkstra(dest, revadj, dc);
        long ans = LLONG_MAX;
        for(int i=0; i<n; i++) {
            if(da[i] == LLONG_MAX || db[i] == LLONG_MAX || dc[i] == LLONG_MAX) {
                continue;
            }
            ans = min(ans, da[i] + db[i] + dc[i]);
        }
        if(ans == LLONG_MAX) {
            return -1;
        }
        return ans;
    }
};