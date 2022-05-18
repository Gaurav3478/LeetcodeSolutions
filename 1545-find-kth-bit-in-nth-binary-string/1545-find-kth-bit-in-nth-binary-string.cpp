class Solution {
public:
    string gen(int n) {
        if(n == 1) {
            return "0";
        }
        string s = gen(n-1);
        string s_reversed = s;
        reverse(s_reversed.begin(), s_reversed.end());
        for(int i=0; i<s_reversed.size(); i++) {
            if(s_reversed[i] == '0') {
                s_reversed[i] = '1';
            }
            else {
                s_reversed[i] = '0';
            }
        }
        return s + "1" + s_reversed;
    }
    char findKthBit(int n, int k) {
        return gen(n)[k-1];        
    }
};