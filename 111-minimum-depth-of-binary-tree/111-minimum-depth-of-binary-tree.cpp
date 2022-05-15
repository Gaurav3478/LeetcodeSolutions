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
    int height(TreeNode *node) {
        if(node == NULL) {
            return 0;
        }
        if(node->left == NULL) {
            return 1 + height(node->right);
        }
        if(node->right == NULL) {
            return 1 + height(node->left);
        }
        return 1+min(height(node->left), height(node->right));
    }
    int minDepth(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        return height(root);
    }
};