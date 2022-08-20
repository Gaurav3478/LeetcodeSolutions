class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        priority_queue<int> pq;
        int curFuel = startFuel;
        bool ok = true;
        for(int i=0; i<n; i++) {
            int stationLoc = stations[i][0];
            int stationFuel = stations[i][1];
            while(stationLoc - curFuel > 0) {
                if(!pq.empty()) {
                    curFuel += pq.top();
                    pq.pop();
                }
                else {
                    ok = false;
                    break;
                }
            }
            if(!ok) {
                break;
            }
            pq.push(stationFuel);
        }
        while(target - curFuel > 0) {
            if(!pq.empty()) {
                curFuel += pq.top();
                pq.pop();
            }
            else {
                ok = false;
                break;
            }
        }
        if(!ok) {
            return -1;
        }
        else {
            return n - pq.size();
        }
    }
};