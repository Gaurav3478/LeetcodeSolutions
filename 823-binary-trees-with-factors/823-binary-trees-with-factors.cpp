class Solution {
public:
    const int MOD = 1e9 + 7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        map<int, long long int> subtrees; //stores the number of ways to make any integer
        
        int ans = 0;
        for(int i=0; i<n; i++) {
            int num = arr[i];
            long long int cnt = 1;
            for(int j=0; j<i; j++) {
                int val = arr[j];
                if(val == num) {
                    continue;
                }
                if(num%val == 0) {
                    if(binary_search(arr.begin(), arr.end(), num/val)) {
                        cnt = (cnt + (subtrees[num/val]%MOD*subtrees[val]%MOD)%MOD)%MOD; 
                    }
                }
            }
            subtrees[num] = cnt%MOD;
            ans = (ans + cnt)%MOD;
        }
        return ans;
    }
};