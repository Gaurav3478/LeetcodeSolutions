class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ans;
        int  n = firstList.size(), m = secondList.size();
        int p1 = 0, p2 = 0;
        while(true) {
            if(p1 == n || p2 == m) {
                break;
            }
            //compare the intervals
            vector<int> intersection;
            bool intersected = true;
            int firstListLeft = firstList[p1][0], firstListRight = firstList[p1][1], secondListLeft = secondList[p2][0], secondListRight = secondList[p2][1];
            intersection.push_back(max(firstListLeft, secondListLeft));
            intersection.push_back(min(firstListRight, secondListRight));
            if(firstListLeft > secondListRight || secondListLeft > firstListRight) {
                intersected = false;
            }
            if(intersected) {
                ans.push_back(intersection);
                //only increment the lower interval
                if(firstListRight < secondListRight) {
                    p1++;
                }
                else {
                    p2++;
                }
            }
            else {
                //ignore the smaller interval
                if(firstListLeft >= secondListRight) {
                    p2++;
                }
                else {
                    p1++;
                }
            }
        }     
        return ans;
    }
};