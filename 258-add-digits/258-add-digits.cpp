class Solution {
public:
    int numDigits(int n) {
        string s = to_string(n);
        return s.size();
    }
    
    int addDigits(int num) {
        while(numDigits(num) > 1) {
            string s = to_string(num);
            int curr_sum = 0;
            for(int i=0; i<s.size(); i++) {
                curr_sum += (s[i] - '0'); 
            }
            num = curr_sum;
        }
        return num;
    }
};