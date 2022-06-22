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
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        inorder(ans, root, k);
        return ans;
    }
    
    void inorder(int &ans, TreeNode* root, int& k) {
        if (!root) return;
        inorder(ans, root->left, k);
        if (--k == 0){
            ans = root->val;
            return;
        } 
        inorder(ans, root->right, k);
    }  
};