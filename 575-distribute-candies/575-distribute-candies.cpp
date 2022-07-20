class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        set<int> s;
        int n = candyType.size();
        for(int i=0; i<n; i++) {
            s.insert(candyType[i]);
        }
        int ans = min((int)s.size(), n/2);
        return ans;
    }
};