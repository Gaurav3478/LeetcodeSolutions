class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        int n = words.size();
        map<string, int> mp;
        
        vector<string> transformations = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        for(int i=0; i<n; i++) {
            int sz = words[i].size();
            string transformation = "";
            for(int j=0; j<sz; j++) {
                char c = words[i][j];
                transformation += (transformations[c - 'a']);   
            }
            mp[transformation]++;
        }
        
        return mp.size();
    }
};