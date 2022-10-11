class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int> vect;
        vect.push_back(nums[0]);
        for(int i=1; i<n; i++) {
            int num = nums[i];
            auto it = lower_bound(vect.begin(), vect.end(), num);
            if(it == vect.end()) {
                vect.push_back(num);
            }
            else {
                auto idx = it - vect.begin();
                vect[idx] = num;
            }
        }
        return vect.size() >= 3;
    }
};