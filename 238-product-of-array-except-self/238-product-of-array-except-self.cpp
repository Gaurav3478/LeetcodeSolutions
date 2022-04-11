class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int arr1[n], arr2[n];
        arr1[0] = nums[0];
        vector<int> ans;
        for(int i=1; i<n; i++) {
            arr1[i] = arr1[i-1]*nums[i];
        }
        arr2[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--) {
            arr2[i] = arr2[i+1]*nums[i];
        }
        for(int i=0; i<n; i++) {
            if(i == 0) {
                // cout << arr2[1] << " ";
                ans.push_back(arr2[1]);
                continue;
            }
            if(i == n-1) {
                // cout << arr1[n-2] << " ";
                ans.push_back(arr1[n-2]);
                continue;
            }
            // cout << arr1[i-1]*arr2[i+1] << " ";
            ans.push_back(arr1[i-1]*arr2[i+1]);
        }
        return ans;
    }
};