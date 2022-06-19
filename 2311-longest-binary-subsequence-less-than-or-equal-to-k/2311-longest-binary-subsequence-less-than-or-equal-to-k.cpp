class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.size();
        int numZeros = 0;
        for(int i=0; i<n; i++) {
            if(s[i] == '0') {
                numZeros++;
            }
        }
        int numOnes = 0;
        int curVal = 1;
        int valSoFar = 0;
        for(int i=n-1; i>=0; i--) {
            if(curVal + valSoFar > k) {
                break;
            }
            if(s[i] == '1') {
                numOnes++;
                valSoFar += curVal;
            }
            curVal *= 2;
        }
        return numZeros + numOnes;
    }
};