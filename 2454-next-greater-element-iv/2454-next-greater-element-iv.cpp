#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template <typename T> using ordered_set = tree<T, null_type,
	less<T>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n = nums.size();
        map<int, vector<int>, greater<int>> mp;
        for(int i=0; i<n; i++) {
            mp[nums[i]].push_back(i);
        }
        
        ordered_set<int> os;
        vector<int> ans(n);
        for(auto [num, vect]: mp) {
            for(auto &idx: vect) {
                int k = os.order_of_key(idx + 1);
                if(os.size() - k >= 2) {
                    int val = *os.find_by_order(k + 1);
                    ans[idx] = nums[val]; 
                }
                else {
                    ans[idx] = -1;
                }
            }
            for(auto idx: vect) {
                os.insert(idx);
            }
        }
        
        return ans;
    }
};