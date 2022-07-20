class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = -1;
        int n = gas.size();
        assert(n == cost.size());
        gas.resize(2*n, 0);
        cost.resize(2*n, 0);
        for(int i=n; i<2*n; i++) {
            gas[i] = gas[i-n];
            cost[i] = cost[i-n];
        }
        int extra = 0;
        for(int i=0; i<n; i++) {
            if(start == -1) {
                start = i;
            }
            if(gas[i] < cost[i]) {
                //this guy cannot be a starting point
                if(gas[i] + extra < cost[i]) {
                    start = -1;
                    extra = 0;
                } 
                else {
                    extra += gas[i] - cost[i];
                }
            }
            else {
                extra += gas[i] - cost[i];
            }
        }
        if(start == -1) {
            return -1;
        }
        extra = 0;
        int ok = true;
        for(int i=start; i<start+n; i++) {
            if(gas[i] + extra < cost[i]) {
                ok = false;
                break;
            }
            extra += gas[i] - cost[i];
        }
        if(ok) {
            return start;
        }
        else {
            return -1;
        }
    }
};