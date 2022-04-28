class Solution {
public:
    int mySqrt(long int x) {
        long int r = x, l = 0;
        long int ans = 0;
        while(l <= r) {
            long int mid = l + (r-l)/2;
            if(mid*mid <= x) {
                l = mid + 1;
                ans = mid;
            }
            else {
                r = mid - 1;
            }
        }
        return ans;
    }
};