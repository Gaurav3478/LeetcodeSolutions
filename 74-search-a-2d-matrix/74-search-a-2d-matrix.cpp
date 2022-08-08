class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        //first find the row, then find the column
        int row = -1;
        int low = 0, high = n - 1;
        while(low <= high) {
            int mid = low + (high - low)/2;
            int val = matrix[mid][m-1];
            if(val == target) {
                row = mid;
                break;
            }         
            else if(val > target) {
                row = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        if(row == -1) {
            return false;
        }
        low = 0, high = m-1;
        while(low <= high) {
            int mid = low + (high - low)/2;
            int val = matrix[row][mid];
            if(val == target) {
                return true;
            }
            else if(val > target) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return false;
    }
};