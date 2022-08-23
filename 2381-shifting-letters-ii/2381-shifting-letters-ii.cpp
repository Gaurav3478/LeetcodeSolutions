class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> diff(n + 1, 0);
        for(int i=0; i<shifts.size(); i++) {
            int a = shifts[i][0], b = shifts[i][1];
            int k = shifts[i][2];
            if(k == 0) {
                diff[a]--;
                diff[b+1]++;
            }
            else {
                diff[a]++;
                diff[b+1]--;
            }
        }
        
        int val = 0;
        for(int i=0; i<n; i++) {
            val += diff[i];
            val %= 26;
            int ch = s[i] - 'a';
            ch = (ch + val + 26)%26;
            char c = ch + 'a';
            s[i] = c;
        }
        
        return s;
    }
};