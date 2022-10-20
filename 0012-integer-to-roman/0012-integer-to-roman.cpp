class Solution {
public:
    string intToRoman(int num) {
        map<int, int> mp;
        int cur = 1;
        while(num) {
            int n = num%10;
            mp[cur] = n;
            num /= 10;
            cur *= 10;
        }
        
        string ans = "";
        if(mp.find(1) != mp.end()) {
            int val = mp[1];
            if(val == 0) {
                
            }
            else if(val == 1) {
                ans = ans + 'I';
            }
            else if(val == 2) {
                ans = ans + "II";
            }
            else if(val == 3) {
                ans = ans + "III";
            }
            else if(val == 4) {
                ans = ans + "IV";
            }
            else if(val == 5) {
                ans = ans + 'V';
            }
            else if(val == 6) {
                ans = ans + "VI";
            }
            else if(val == 7) {
                ans = ans + "VII";
            }
            else if(val == 8) {
                ans = ans + "VIII";
            }
            else if(val == 9) {
                ans = ans + "IX";
            }
        }
        
        if(mp.find(10) != mp.end()) {
            int val = mp[10];
            if(val == 0) {
        
            }
            else if(val == 1) {
                ans = 'X' + ans;
            }
            else if(val == 2) {
                ans = "XX" + ans;
            }
            else if(val == 3) {
                ans = "XXX" + ans;
            }
            else if(val == 4) {
                ans = "XL" + ans;
            }
            else if(val == 5) {
                ans = "L" + ans;
            }
            else if(val == 6) {
                ans = "LX" + ans;
            }
            else if(val == 7) {
                ans = "LXX" + ans;
            }
            else if(val == 8) {
                ans = "LXXX" + ans;
            }
            else if(val == 9) {
                ans = "XC" + ans;
            }
        }
        
        if(mp.find(100) != mp.end()) {
            int val = mp[100];
            if(val == 0) {
        
            }
            else if(val == 1) {
                ans = 'C' + ans;
            }
            else if(val == 2) {
                ans = "CC" + ans;
            }
            else if(val == 3) {
                ans = "CCC" + ans;
            }
            else if(val == 4) {
                ans = "CD" + ans;
            }
            else if(val == 5) {
                ans = "D" + ans;
            }
            else if(val == 6) {
                ans = "DC" + ans;
            }
            else if(val == 7) {
                ans = "DCC" + ans;
            }
            else if(val == 8) {
                ans = "DCCC" + ans;
            }
            else if(val == 9) {
                ans = "CM" + ans;
            }
        }
        
        if(mp.find(1000) != mp.end()) {
            int val = mp[1000];
            if(val == 0) {
        
            }
            else if(val == 1) {
                ans = 'M' + ans;
            }
            else if(val == 2) {
                ans = "MM" + ans;
            }
            else if(val == 3) {
                ans = "MMM" + ans;
            }
        }
        
        return ans;
    }
};