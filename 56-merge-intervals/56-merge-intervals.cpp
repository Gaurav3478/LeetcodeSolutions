class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        //for each interval, we'll check if it's part of the previous interval: if it is, merge, else create a new interval
        int n = intervals.size();
        vector<int> prev_interval = intervals[0];
        for(int i=1; i<n; i++) {
            vector<int> cur_interval = intervals[i];
            if(cur_interval[0] <= prev_interval[1]) {
                cur_interval[0] = prev_interval[0];
                cur_interval[1] = max(cur_interval[1], prev_interval[1]);
            }
            else {
                ans.push_back(prev_interval);
            }
            prev_interval = cur_interval;
        }
        ans.push_back(prev_interval);
        return ans;
    }
};