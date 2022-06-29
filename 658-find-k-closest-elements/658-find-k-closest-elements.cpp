class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int idx = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int low = idx - 1, high = idx;
        vector<int> ans;
        while(ans.size() < k) {
            if(high > n - 1) {
                ans.push_back(arr[low]);
                low--;
            }
            else if(low < 0) {
                ans.push_back(arr[high]);
                high++;
            }
            else if(x - arr[low] <= arr[high] - x) {
                ans.push_back(arr[low]);
                low--;
            }
            else {
                ans.push_back(arr[high]);
                high++;
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};