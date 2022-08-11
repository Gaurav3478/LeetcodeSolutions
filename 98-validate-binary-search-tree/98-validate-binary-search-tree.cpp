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
    bool solve(TreeNode *root, long high, long low) {
        if(!root) {
            return true;
        }
        if(root->val <= high || root->val >= low) {
            return false;
        }
        return solve(root->left, high, root->val) && solve(root->right, root->val, low);
    }
    
    bool isValidBST(TreeNode* root) {
        long prevHigh = LONG_MIN, prevLow = LONG_MAX;
        return solve(root, prevHigh, prevLow);
    }
};