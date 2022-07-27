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
      TreeNode *solve(TreeNode *root) {
          if(!root) {
              return NULL;
          }
          TreeNode *leftTail = solve(root->left);
          TreeNode *rightTail = solve(root->right);
          if(leftTail) {
              leftTail->right = root->right;
              root->right = root->left;
              root->left = NULL;
          }
          TreeNode *last = root;
          if(rightTail) {
              last = rightTail; 
          }
          else if(leftTail) {
              last = leftTail;
          }
          return last;
      }
    
    void flatten(TreeNode* root) {
        solve(root);
    }
};