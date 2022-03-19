#include<bits/stdc++.h>
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> i_indexes;
        vector<int> j_indexes;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(matrix[i][j] == 0) {
                    i_indexes.push_back(i);
                    j_indexes.push_back(j);
                }
            }
        }
        while(!i_indexes.empty()) {
            auto itr = i_indexes.begin();
            for(int j=0; j<n; j++) {
                matrix[*itr][j] = 0;
            }
            i_indexes.erase(i_indexes.begin());
        }
        while(!j_indexes.empty()) {
            auto itr = j_indexes.begin();
            for(int i=0; i<m; i++) {
                matrix[i][*itr] = 0;
            }
            j_indexes.erase(j_indexes.begin());
        }
        
    }
};