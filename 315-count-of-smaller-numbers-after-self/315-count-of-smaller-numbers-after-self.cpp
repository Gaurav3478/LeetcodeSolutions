#include <bits/stdc++.h>
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace __gnu_pbds;

template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        ordered_set<pair<int, int>> os;
        int n = nums.size();
        vector<int> ans(n);
        for(int i=n-1; i>=0; i--) {            
            ans[i] = os.order_of_key({nums[i], 0});
            os.insert({nums[i], i});
        }
        return ans;
    }
};