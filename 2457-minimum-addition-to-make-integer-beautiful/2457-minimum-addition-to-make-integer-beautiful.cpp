class Solution {
public:
    int sOd(long x) {
        int sum = 0;
        while(x) {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }
    
    long long makeIntegerBeautiful(long long n, int target) {
        long mul = 1;
        long add = 0;
        while(sOd(n + add) > target) {
            mul *= 10;
            add = mul - n % mul;
        }
        
        return add;
    }
};