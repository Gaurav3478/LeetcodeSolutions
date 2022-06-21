class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int i=0, j=0, ans = 0;
        unordered_map<int, int> mp;
        while(j < n) {
            mp[fruits[j]]++;
            while(mp.size() > 2) {
                if(mp[fruits[i]] == 1) {
                    mp.erase(fruits[i]);
                }
                else {
                    mp[fruits[i]]--;
                }
                i++;
            }
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};