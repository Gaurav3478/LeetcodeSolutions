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
    TreeNode *solve(TreeNode *root, int pval, int qval) {
        int val = root->val;
        if(val == pval || val == qval) {
            return root;
        }
        else if(val > pval && val > qval) {
            return solve(root->left, pval, qval);
        }
        else if(val < pval && val < qval) {
            return solve(root->right, pval, qval);
        }
        else {
            return root;
        }
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int pval = p->val, qval = q->val;
        return solve(root, pval, qval);
    }
};