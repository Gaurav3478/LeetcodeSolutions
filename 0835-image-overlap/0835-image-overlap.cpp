class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<pair<int, int>> img1_coordinates, img2_coordinates;
        int n = img1.size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(img1[i][j] == 1) {
                    img1_coordinates.push_back({i, j});
                }
                if(img2[i][j] == 1) {
                    img2_coordinates.push_back({i, j});
                }
            }
        }
        
        map<pair<int, int>, int> mp;
        int ans = 0;
        for(auto [i1, j1]: img2_coordinates) {
            for(auto [i2, j2]: img1_coordinates) {
                mp[{i1 - i2, j1 - j2}]++;
                ans = max(ans, mp[{i1 - i2, j1 - j2}]);
            }
        }
        
        return ans;
    }
};