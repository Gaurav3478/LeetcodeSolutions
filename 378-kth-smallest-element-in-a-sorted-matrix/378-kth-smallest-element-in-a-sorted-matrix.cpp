class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<int, vector<int>> pq;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                pq.push(matrix[i][j]);
                cout << pq.top() << endl;
                if(pq.size() > k) {
                    pq.pop();
                }
            }
        }
        return pq.top();
    }
};