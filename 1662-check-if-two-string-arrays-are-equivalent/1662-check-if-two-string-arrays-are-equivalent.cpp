class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int n = 0, m = 0;
        int p1 = 0, p2 = 0;
        while(n < word1.size() && m < word2.size()) {
            if(word1[n][p1] != word2[m][p2]) {
                return false;
            }
            p1++;
            p2++;
            if(p1 == word1[n].size()) {
                p1 = 0;
                n++;
            }
            if(p2 == word2[m].size()) {
                p2 = 0;
                m++;
            }
        }
        
        if(n == word1.size() && m == word2.size()) {
            return true;
        }
        else {
            return false;
        }
    }
};