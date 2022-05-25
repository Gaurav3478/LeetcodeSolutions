class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftProduct(n), rightProduct(n);
        for(int i=0; i<n; i++) {
            if(i==0) {
                leftProduct[i] = nums[i];
            }
            else {
                leftProduct[i] = leftProduct[i-1]*nums[i];
            }
        }
        for(int i=n-1; i>=0; i--) {
            if(i==n-1) {
                rightProduct[i] = nums[i];
            }
            else {
                rightProduct[i] = rightProduct[i+1]*nums[i];
            }
        }
        for(auto it: leftProduct) {
            cout << it << " ";
        }
        cout << endl;
        for(auto it: rightProduct) {
            cout << it << " ";
        }
        vector<int> ans;
        for(int i=0; i<n; i++) {
            if(i==0) {
                ans.push_back(rightProduct[1]);
            }
            else if(i==n-1) {
                ans.push_back(leftProduct[n-2]);
            }
            else {
                ans.push_back(leftProduct[i-1] * rightProduct[i+1]);
            }
        }
        return ans;
    }
};