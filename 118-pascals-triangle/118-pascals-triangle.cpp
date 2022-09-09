class Solution {
public:
    vector<vector<int> > generate(int numRows) {
         vector<vector<int>> r(numRows);
            r[0].push_back(1);
        if(numRows == 1) {
            return r;
        }
            r[1].push_back(1);
            r[1].push_back(1);
        if(numRows == 2) {
            return r;
        }
        for (int i = 2; i < numRows; i++) {
            r[i].push_back(1);
  
            for (int j = 1; j < i; j++){
                int v = r[i - 1][j - 1] + r[i - 1][j];
                r[i].push_back(v);
            }
            r[i].push_back(1);
        }
        
        return r;
    }
};