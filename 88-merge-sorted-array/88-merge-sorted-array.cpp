class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int ptr1 = 0, ptr2 = 0;
        if(n==0) {
            return;
        }
        for(int i=0; i<m+n; i++) {
            if(ptr1 >= m) {
                nums1[ptr1] = nums2[ptr2];
                ptr1++;
                ptr2++;
                continue;
            }
            if(nums1[ptr1] <= nums2[ptr2]) {
                ptr1++;
            }
            else if(nums2[ptr2] < nums1[ptr1]) {
                swap(nums2[ptr2], nums1[ptr1]);
                sort(nums2.begin(), nums2.end());
                ptr1++;
            }
        }   
    }
};