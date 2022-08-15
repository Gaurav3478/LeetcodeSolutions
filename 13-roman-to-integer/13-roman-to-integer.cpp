class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        int ans = 0;
        map<char, int> val;
        val['I'] = 1;
        val['V'] = 5;
        val['X'] = 10;
        val['L'] = 50;
        val['C'] = 100;
        val['D'] = 500;
        val['M'] = 1000;
        for(int i=0; i<n; i++) {
            char c = s[i];
            if(i == n-1) {
                ans += val[c];
            }
            else {
                if(c == 'I' && s[i+1] == 'V') {
                    ans += 4;
                    i++;
                }
                else if(c == 'I' && s[i+1] == 'X') {
                    ans += 9;
                    i++;
                }
                else if(c == 'X' && s[i+1] == 'L') {
                    ans += 40;
                    i++;
                }
                else if(c == 'X' && s[i+1] == 'C') {
                    ans += 90;
                    i++;
                }
                else if(c == 'C' && s[i+1] == 'D') {
                    ans += 400;
                    i++;
                }
                else if(c == 'C' && s[i+1] == 'M') {
                    ans += 900;
                    i++;
                }
                else {
                    ans += val[c];
                }
            }
        }
        return ans;
    }
};