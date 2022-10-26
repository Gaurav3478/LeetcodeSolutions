#define ll long long
class Solution {
public:
    ll find_cost(ll x, vector<int> &nums, vector<int> &cost) {
        ll ans = 0;
        for(ll i=0; i<nums.size(); i++) {
            ans += cost[i]*(abs(nums[i] - x));
        }
        return ans;
    }
    
    long long minCost(vector<int>& nums, vector<int>& cost) {
        ll low = 0, high = 1e6;
        while(low < high) {
            ll mid1 = low + (high - low)/2;
            ll mid2 = mid1 + 1;
            ll val1 = find_cost(mid1, nums, cost), val2 = find_cost(mid2, nums, cost);
            if(val1 < val2) {
                high = mid1;
            }
            else {
                low = mid2;
            }
        }
        return find_cost(low, nums, cost);
    }
};