class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s2.size();
        vector<int> mp1(26, 0), mp2(26, 0);
        int k = s1.size();
        if(k > n) {
            return false;
        }
        for(int i=0; i<k; i++) {
            mp1[s1[i] - 'a']++;
        }
        for(int i=0; i<k; i++) {
            mp2[s2[i] - 'a']++;
        }
        if(mp1 == mp2) {
            return true;
        }
        for(int i=k; i<n; i++) {
            mp2[s2[i-k] - 'a']--;
            mp2[s2[i] - 'a']++;
            if(mp1 == mp2) {
                return true;
            }
        }
        return false;
    }
};