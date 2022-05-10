class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<int> ans;
        map<int, int> mp;
        for(int i=0; i<n2; i++) {
            for(int j=i+1; j<n2; j++) {
                if(nums2[j] > nums2[i]) {
                    mp[nums2[i]] = nums2[j];
                    break;
                }
            }
        }
        for(int i=0; i<n1; i++) {
            if(mp.find(nums1[i]) == mp.end()) {
                ans.push_back(-1);
            }
            else {
                ans.push_back(mp[nums1[i]]);
            }
        }
        return ans;
    }
};