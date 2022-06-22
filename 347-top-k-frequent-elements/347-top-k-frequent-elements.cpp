class Solution {
public:
    struct frequencywise {
        bool operator()(pair<int, int> &a, pair<int, int> &b) {
            return a.second < b.second;
        }  
    };
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            mp[nums[i]]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, frequencywise> pq;
        for(auto it: mp) {
            pq.push({it.first, it.second});
        }
        vector<int> ans(k);
        for(int i=0; i<k; i++) {
            pair<int, int> p = pq.top();
            pq.pop();
            ans[i] = p.first;
        }
        return ans;
    }
};