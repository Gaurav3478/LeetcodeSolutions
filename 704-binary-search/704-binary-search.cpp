class Solution {
public:
    int binSearch(vector<int> &vect, int target) {
        int n = vect.size();
        int low = 0, high = n-1;
        int mid, ans = -1;
        while(low <= high) {
            mid = low + (high - low)/2;
            if(vect[mid] == target) {
                ans = mid;
                break;
            }
            else if(vect[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return ans;
    }

    int search(vector<int>& nums, int target) {
        return binSearch(nums, target);
    }
};