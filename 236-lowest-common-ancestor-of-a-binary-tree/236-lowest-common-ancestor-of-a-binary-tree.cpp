/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode * findLCA(TreeNode *node, TreeNode *p, TreeNode *q) {
        if(node == p || node == q || node == NULL) {
            return node;
        }
        TreeNode *left = findLCA(node->left, p, q);
        TreeNode *right = findLCA(node->right, p, q);
        if(!left) {
            return right;
        }
        if(!right) {
            return left;
        }
        return node;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return findLCA(root, p, q);
    }
};