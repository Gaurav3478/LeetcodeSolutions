class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), [] (vector<int> &a, vector<int> &b){
            if(a[0] == b[0]) {
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });
        vector<int> temp;
        temp.push_back(envelopes[0][1]);
        for(int i=1; i<n; i++) {
            int val = envelopes[i][1];
            if(val > temp.back()) {
                temp.push_back(val);
            }
            else {
                int idx = lower_bound(temp.begin(), temp.end(), val) - temp.begin();
                temp[idx] = val;
            }
        }
        return temp.size();
    }
};