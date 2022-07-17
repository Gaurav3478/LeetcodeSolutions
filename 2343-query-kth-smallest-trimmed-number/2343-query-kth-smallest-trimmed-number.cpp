class Solution {
public:
    static bool cmp(pair<string, int> &a, pair<string, int> &b) {
        if (a.first.size() == b.first.size()) {
            if(a.first == b.first) {
                return a.second < b.second;
            }
            return a.first < b.first;
        }
        else {
            return a.first.size() < b.first.size();
        }
    }

    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();
        int len = nums[0].size();
        vector<int> ans(q);
        vector<pair<string, int>> vect;
        for(int i=0; i<n; i++) {
            vect.push_back({nums[i], i});
        }
        for(int i=0; i<q; i++) {
            int k = queries[i][0];
            int trim = queries[i][1];
            nth_element(vect.begin(), vect.begin() + k - 1, vect.end(), [&](pair<string, int> &a, pair<string, int> &b) {
                int cmp = a.first.compare(len - trim, trim, b.first, len - trim, trim);
                if(cmp == 0) {
                    return a.second < b.second;
                }
                return cmp < 0;
            });
            ans[i] = vect[k-1].second;
        }
        return ans;
    }
};