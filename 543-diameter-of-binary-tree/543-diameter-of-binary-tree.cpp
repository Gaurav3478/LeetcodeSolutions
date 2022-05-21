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
    int findDiameter(TreeNode *node, int &ans) {
        if(node == NULL) {
            return 0;
        }
        int lh = findDiameter(node->left, ans);
        int rh = findDiameter(node->right, ans);
        ans = max(ans, lh + rh);
        return 1 + max(lh, rh);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        findDiameter(root, ans);
        return ans;
    }
};