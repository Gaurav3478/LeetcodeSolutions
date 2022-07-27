class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) {
            return false;
        }
        long long y = 0;
        int x_copy = x;
        while(x > 0) {
            y = 10*y + x%10;
            x/=10;
        }
        if(x_copy == y) {
            return true;
        }
        return false;
    }
};