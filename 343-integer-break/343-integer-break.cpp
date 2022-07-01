class Solution {
public:
    int integerBreak(int n) {
        int ans = 1;
        if(n == 2) {
            return 1;
        }
        if(n == 3) {
            return 2;
        }
        while(n > 0) {
            if(n > 4  || n == 3) {
                ans *= 3;
                n -= 3; 
            }
            else {
                ans *= 2;
                n -= 2;
            }
        }
        return ans;
    }
};