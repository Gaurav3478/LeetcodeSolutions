class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
      int n = nums.size();
      int l = 0, r = n - 1;
      int cur = n-1;
      vector<int> ans(n);
      while(l <= r) {
        if(abs(nums[l]) >= abs(nums[r]) > 0) { 
          ans[cur] = nums[l]*nums[l]; 
          l++;
        }
        else {
          ans[cur] = nums[r]*nums[r];
          r--;
        }
        cur--;
      }
      return ans;
    }
};