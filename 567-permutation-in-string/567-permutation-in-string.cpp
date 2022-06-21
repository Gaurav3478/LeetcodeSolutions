class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s2.size();
        map<char, int> mp1, mp2;
        int k = s1.size();
        if(k > n) {
            return false;
        }
        for(int i=0; i<k; i++) {
            mp1[s1[i]]++;
        }
        for(int i=0; i<k; i++) {
            mp2[s2[i]]++;
        }
        if(mp1 == mp2) {
            return true;
        }
        for(int i=k; i<n; i++) {
            if(mp2[s2[i-k]] == 1) {
                mp2.erase(s2[i-k]);
            }
            else {
                mp2[s2[i-k]]--;
            }
            mp2[s2[i]]++;
            if(mp1 == mp2) {
                return true;
            }
        }
        return false;
    }
};