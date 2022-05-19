class Solution {
public:
    int solve(uint32_t n) {
        int count = 0;
        while(n) {
            count++;
            n &= (n-1);
        }
        return count;
    }

    int hammingWeight(uint32_t n) {
        return solve(n);
    }
};