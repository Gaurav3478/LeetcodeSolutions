class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        //binary search on row first then on column
        int low = 0, high = n-1;
        int mid;
        while (low < high) {
            mid = low + (high - low)/2;
            // moving l up if needed
            if (matrix[mid].back() < target) low = mid + 1;
            // moving r down if needed
            else if (matrix[mid][0] > target) high = mid - 1;
            // we found our row!
            else {
                low = mid;
                break;
            };
        }
        int row = low;
        low = 0, high = m-1;
        while(low <= high) {
            mid = low + (high - low)/2;
            if(matrix[row][mid] > target) {
                high = mid - 1;
            }
            else if(matrix[row][mid] < target) {
                low = mid + 1;
            }
            else {
                return true;
            }
        }
        return false;
    }
};