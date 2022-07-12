class Solution {
public:
    bool solve(vector<int> &matchsticks, vector<int> &vect, int sideLength, int idx) {
        if(idx == matchsticks.size()) {
            return (vect[0] == sideLength && vect[0] == vect[1] && vect[1] == vect[2] && vect[2] == vect[3]);
        }
        for(int i=0; i<4; i++) {
            if(vect[i] + matchsticks[idx] > sideLength) {
                continue;
            }
            vect[i] += matchsticks[idx];
            if(solve(matchsticks, vect, sideLength, idx + 1)) {
                return true;
            }
            vect[i] -= matchsticks[idx];
        }
        return false;
    }
    
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size();
        int sum = 0;
        for(int i=0; i<n; i++) {
            sum += matchsticks[i];
        }
        if(sum%4 != 0) {
            return false;
        }
        int sideLength = sum/4;
        //generate all subsets and see if they all have a length of sideLength
        vector<int> vect(4, 0);
        sort(matchsticks.rbegin(), matchsticks.rend());
        return solve(matchsticks, vect, sideLength, 0);
    }
};