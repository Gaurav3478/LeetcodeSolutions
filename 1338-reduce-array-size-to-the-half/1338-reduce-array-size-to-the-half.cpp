class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int, int> mp;
        int n = arr.size();
        for(int i=0; i<n; i++) {
            mp[arr[i]]++;
        }
        multiset<int> freqs;
        int freq = n;
        for(auto it: mp) {
            freqs.insert(it.second);
        }
        int ans = 0;
        auto it = freqs.rbegin();
        while(freq > n/2) {
            freq -= *it;
            it++;
            ans++;
        }
        return ans;
    }
};