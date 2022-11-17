class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int low = 0, high = n - 1;
        while(low < high) {
            int mid0 = low + (high - low)/2;
            int mid1 = mid0 + 1;
            if(arr[mid0] > arr[mid1]) {
                high = mid0;
            }
            else {
                low = mid1;
            }
        }
        return low;
    }
};