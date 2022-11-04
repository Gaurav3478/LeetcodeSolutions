class Solution {
public:
    string reverseVowels(string s) {
        int n = s.size();
        int l = 0, r = n - 1;
        set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        while(l < n && vowels.find(s[l]) == vowels.end()) {
            l++;
        }
        while(r >= 0 && vowels.find(s[r]) == vowels.end()) {
            r--;
        }
        
        while(r > l) {
            swap(s[l], s[r]);
            l++;
            r--;
            while(l < n && vowels.find(s[l]) == vowels.end()) {
                l++;
            }
            while(r >= 0 && vowels.find(s[r]) == vowels.end()) {
                r--;
            }
        }
        return s;
    }
};