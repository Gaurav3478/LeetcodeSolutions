class Solution {
public:
    string getPermutation(int n, int k) {
        string ans = "";
        k--;
        int fact = 1;
        vector<int> nums;
        for(int i=1; i<n; i++) {
            fact *= i;
            nums.push_back(i);
        }
        nums.push_back(n);
        while(true) {
            cout << "k: " << k << endl;
            cout << "fact: " << fact << endl;
            ans += to_string(nums[k/fact]);
            nums.erase(nums.begin() + k/fact);
            if(nums.empty()) {
                break;
            }
            k %= fact;
            fact = fact/nums.size();
        }
        return ans;

    }
};