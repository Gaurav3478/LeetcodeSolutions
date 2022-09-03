class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int n = chargeTimes.size();
        int i = 0, j = 0;
        multiset<long long int> ms;
        long long int val = 0;
        int cnt = 0;
        while(j < n) {
            ms.insert(chargeTimes[j]);
            val += runningCosts[j];
            while(!ms.empty() && *ms.rbegin() + (j - i + 1)*val > budget) {
                val -= runningCosts[i];
                ms.erase(ms.find(chargeTimes[i]));
                i++;
            }
            cnt = max(cnt, j - i + 1);
            j++;
        }
        return cnt;
    }
};