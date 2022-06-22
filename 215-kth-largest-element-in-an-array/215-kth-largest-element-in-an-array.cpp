class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(auto it: nums) {
            pq.push(it);
        }
        for(int i=0; i<k-1; i++) {
            pq.pop();
        }
        return pq.top();
    }
};