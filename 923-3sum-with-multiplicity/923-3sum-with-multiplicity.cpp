const int MOD = 1e9+7;
class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int n = arr.size();
        map<int, int> mp;
        long int ans = 0;
        for(int i=0; i<n; i++) {
            mp[arr[i]]++;
        }
        for(auto i: mp) {
            for(auto j: mp) { 
                int k = target - i.first - j.first;
                if(!mp.count(k)) {
                    continue;
                }
                else if(i.first == j.first && j.first == k) {
                    ans = (ans + 1LL*mp[i.first]*(mp[i.first]-1)*(mp[i.first]-2)/6)%MOD;
                }
                else if(i.first == j.first && j.first !=k) {
                    ans = (ans + 1LL*mp[i.first]*(mp[i.first]-1)*mp[k]/2)%MOD;
                }
                else if(i.first < j.first && j.first < k) {
                    ans = (ans + 1LL*mp[i.first]*mp[j.first]*mp[k])%MOD;
                }
            }
        }
        ans %= MOD;
        return ans;
    }
};