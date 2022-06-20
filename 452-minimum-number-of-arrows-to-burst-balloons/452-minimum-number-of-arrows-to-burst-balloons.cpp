class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end());
        vector<vector<int>> mergedPoints;
        vector<int> cur = points[0];
        for(int i=1; i<n; i++) {
            if(points[i][0] <= cur[1]) {
                cur[1] = min(cur[1], points[i][1]);
            }
            else {
                mergedPoints.push_back(cur);
                cur = points[i];
            }
        }
        mergedPoints.push_back(cur);
        return mergedPoints.size();
    }
};