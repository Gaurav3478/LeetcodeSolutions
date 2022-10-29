class Solution {
public:
    static bool cmp(pair<int, pair<int, int>> &a, pair<int, pair<int, int>> &b) {
        if(a.second.second == b.second.second) {
            return a.second.first > b.second.first;
        }
        return a.second.second > b.second.second;
    }
    
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();
        vector<pair<int, pair<int, int>>> vect(n);
        for(int i=0; i<n; i++) {
            vect[i] = {plantTime[i] + growTime[i], {plantTime[i], {growTime[i]}}};
        }
        
        sort(vect.begin(), vect.end(), cmp);
        int ans = 0;
        int time = 0;
        for(int i=0; i<n; i++) {
            int val = time + vect[i].first;
            time += vect[i].second.first;
            ans = max(ans, val);
        }
        return ans;
    }
};