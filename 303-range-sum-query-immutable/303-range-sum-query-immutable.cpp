class NumArray {
private:
    vector<int> memo = {0};

public:
    NumArray(vector<int> &nums) {
        int summ = 0;
        for (int n : nums) {
            summ += n;
            memo.push_back(summ);
        }
    }

    int sumRange(int i, int j) {
        return memo[j+1] - memo[i];
    }
};