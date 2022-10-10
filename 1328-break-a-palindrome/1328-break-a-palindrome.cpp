class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        if(n == 1) {
            return "";
        }
        if(n%2 == 0) {
            char cur = 'a';
            for(int i=0; i<n; i++) {
                if(palindrome[i] != 'a') {
                    palindrome[i] = 'a';
                    return palindrome;
                }
            }
            palindrome[n - 1] = 'b';
            return palindrome;
        }
        else {
            char mid = palindrome[n/2];
            for(int i=0; i<n/2; i++) {
                if(palindrome[i] != 'a') {
                    palindrome[i] = 'a';
                    return palindrome;
                }
            }
            palindrome[n - 1] = 'b';
            return palindrome;
        }
    }
};