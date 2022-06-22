class Solution {
public:
    string frequencySort(string s) {
        map<char, int> mp;
        int n = s.size();
        for(int i=0; i<n; i++) {
            mp[s[i]]++;
        }
        priority_queue<pair<int, char>> pq;
        for(auto it: mp) {
            pq.push({it.second, it.first});
        }
        string ans = "";
        while(!pq.empty()) {
            pair<int, char> p = pq.top();
            pq.pop();
            //frequency is first, character is second
            char c = p.second;
            int f = p.first;
            ans += string(f, c);
        }
        return ans;
    }
};