class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int n = height.size();
        int left = 0, right = n - 1;
        while(left < right) {
            int h = min(height[left], height[right]);
            int d = right - left;
            int val = d*h;
            ans = max(ans, val);
            if(height[left] < height[right]) {
                left++;
            }
            else {
                right--;
            }
        }
        return ans;
    }
};