class Solution {
public:
    bool isPossible(vector<int>& nums) {
        map<int, int> ones, twos, threes;
        for(auto num: nums) {
            if(ones.find(num - 1) != ones.end()) {
                ones[num-1]--;
                if(ones[num-1] == 0) {
                    ones.erase(num-1);
                }
                twos[num]++;
                continue;
            }
            if(twos.find(num-1) != twos.end()) {
                twos[num-1]--;
                if(twos[num-1] == 0) {
                    twos.erase(num-1);
                }
                threes[num]++;
                continue;
            }
            if(threes.find(num-1) != threes.end()) {
                threes[num-1]--;
                if(threes[num-1] == 0) {
                    threes.erase(num-1);
                }
                threes[num]++;
                continue;
            }
            ones[num]++;
        }
        if(ones.size() > 0 || twos.size() > 0) {
            return false;
        }
        return true;
    }
};