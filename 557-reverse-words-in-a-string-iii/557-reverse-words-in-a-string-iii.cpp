class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int j = 0;
        for(int i=0; i<n; i++) {
            if(i < n - 1 && s[i + 1] == ' ' || i == n - 1) {
                reverse(s.begin() + j, s.begin() + i + 1);
                j = i + 2;
            }
        }
        return s;
    }
};