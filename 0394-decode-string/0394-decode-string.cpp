class Solution {
public:
    int i;
    set<char> digits = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    
    bool isDigit(char c) {
        if(digits.find(c) != digits.end()) {
            return true;
        }
        return false;
    }
    
    string expandStack(string s) {
        string ans = "";
        while(s[i] != '[') {
            if(s[i] == ']') {
                i--;
                string temp = expandStack(s);
                reverse(temp.begin(), temp.end());
                ans += temp;
                i++;
            }
            else {
                ans += s[i];
            }
            i--;
        }
        i--;
        string dig;
        while(i >= 0 && isDigit(s[i])) {
            dig += s[i];
            i--;
        }
        reverse(dig.begin(), dig.end());
        int digit;
        reverse(ans.begin(), ans.end());
        digit = stoi(dig);
        string ret = "";
        for(int i=0; i<digit; i++) {
            ret += ans;
        }
        return ret;
    }
    
    string decodeString(string s) {
        string ans = "";
        int n = s.size();
        for(i=n-1; i>=0; i--) {
            if(s[i] == ']') {
                i--;
                ans = expandStack(s) + ans;
                i++;
            }
            else if(!isDigit(s[i])) {
                ans = s[i] + ans;
            }
        }
        return ans;
    }
};