class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //fact is that we only care about the previous interval in the sorted order
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        int curRight = intervals[0][1];
        int ans = 0;
        for(int i=1; i<n; i++) {
            if(intervals[i][0] >= curRight) {
                //no intersection
                curRight = intervals[i][1];
            }
            else {
                ans++;
                if(intervals[i][1] < curRight) {
                    curRight = intervals[i][1];
                }
            }
        }
        return ans;
    }   
};