class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int ans = 0;
        map<char, int> mp;
        int len = tasks.size();
        for(int i=0; i<len; i++) {
            mp[tasks[i]]++;
        }
        priority_queue<int> pq;
        for(auto it: mp) {
            pq.push(it.second);
        }
        while(!pq.empty()) {
            vector<int> vect;
            for(int i=0; i<n+1; i++) {
                if(!pq.empty()) {
                    int x = pq.top();
                    pq.pop();
                    x--;
                    vect.push_back(x);
                }
            }
            int sz = vect.size();
            for(auto it: vect) {
                if(it != 0) {
                    pq.push(it);
                }
            }
            ans += pq.empty()?sz:n+1;
        }
        return ans;
    }
};