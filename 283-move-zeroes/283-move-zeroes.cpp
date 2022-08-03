class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int numZeroes = 0;
        for(int i=0; i<n; i++) {
            if(nums[i] == 0) {
                numZeroes++;
            }
        }
        int rem = n - numZeroes;
        int ptr = 0;
        int v = 0;
        while(ptr < rem) {
            v = max(v, ptr);
            if(nums[v] == 0) {
                while(v < n && nums[v] == 0) {
                    v++;
                }
                swap(nums[v], nums[ptr]);
            }
            ptr++;
        }
        for(int i=rem; i<n; i++) {
            nums[i] = 0;
        }
    }
};