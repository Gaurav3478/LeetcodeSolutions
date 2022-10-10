class Solution {
public:
    bool check(long long x, vector<long long> &vect, vector<long long> &spare) {
        vector<long long> spare_copy = spare;
        int n = vect.size(), m = spare_copy.size();
        long long j = 0;
        for(int i=0; i<n; i++) {
            if(vect[i] < x) {
                if(j >= m) {
                    return false;
                }
                long long req = x - vect[i];
                while(j < m && req > 0) {
                    if(req >= spare_copy[j]) {
                        req -= spare_copy[j];
                        j++;
                    }
                    else {
                        spare_copy[j] -= req;
                        req = 0;
                    }
                }
                if(req > 0) {
                    return false;
                }
            }
        }
        return true;
    }
    
    long long maxRunTime(int n, vector<int>& batteries) {
        long long ans = -1;
        int m = batteries.size();
        sort(batteries.rbegin(), batteries.rend());
        if(m < n) {
            return 0;
        }
        
        
        long long low = 0, high = 1e14;
        vector<long long> vect, spare;
        for(int i=0; i<n; i++) {
            vect.push_back(batteries[i]);
        }
        for(int i=n; i<m; i++) {
            spare.push_back(batteries[i]);
        }
                
        while(low <= high) {
            long long mid = low + (high - low)/2;
            if(check(mid, vect, spare)) {
                low = mid + 1;
                ans = mid;
            }
            else {
                high = mid - 1;
            }
        }
        return ans;
    }
};