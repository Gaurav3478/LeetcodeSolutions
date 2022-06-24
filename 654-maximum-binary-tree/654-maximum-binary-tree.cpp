/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode *construct(vector<int> &nums, int l, int r) {
        if(l > r) {
            return NULL;
        }
        int maxIdx = max_element(nums.begin() + l, nums.begin() + r + 1) - nums.begin();
        return new TreeNode(nums[maxIdx], construct(nums, l, maxIdx - 1), construct(nums, maxIdx + 1, r));
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return construct(nums, 0, nums.size() - 1);
    }
};