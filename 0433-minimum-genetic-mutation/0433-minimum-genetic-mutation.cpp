class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        int n = bank.size();
        queue<string> Q;
        Q.push(start);
        vector<int> vis(n, false);
        int ans = 0;
        if(start == end) {
            return 0;
        }
        while(!Q.empty()) {
            int sz = Q.size();
            for(int qq=0; qq<sz; qq++) {
                string s = Q.front();
                Q.pop();
                if(s == end) {
                    return ans;
                }
                for(int i=0; i<n; i++) {
                    if(vis[i]) {
                        continue;
                    }
                    int diff = 0;
                    for(int j=0; j<8; j++) {
                        if(s[j] != bank[i][j]) {
                            diff++;
                        }
                    }
                    if(diff == 1) {
                        vis[i] = true;
                        Q.push(bank[i]);
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};