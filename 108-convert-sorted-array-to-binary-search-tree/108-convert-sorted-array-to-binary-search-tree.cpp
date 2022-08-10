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
    TreeNode *solve(int low, int high, vector<int> &nums) {
        if(low < high) {
            int mid = low + (high - low)/2;
            TreeNode *root = new TreeNode(nums[mid]);
            root->left = solve(low, mid, nums);
            root->right = solve(mid + 1, high, nums);
            return root;
        }
        else {
            return NULL;
        }
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n;
        return solve(low, high, nums);
    }
};