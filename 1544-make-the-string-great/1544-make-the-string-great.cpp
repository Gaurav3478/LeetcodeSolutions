class Solution {
public:
    string makeGood(string s) {
        bool cont = true;
        while(cont) {
            string t = s;
            cont = false;
            for(int i=0; i<int(s.size()-1); i++) {
                if(s[i]+32 == s[i+1] || s[i]-32 == s[i+1]) {
                    cont = true;
                    t = s.substr(0, i) + s.substr(i+2);
                    break;
                }
            }
            s = t;
        }
        return s;
    }
};