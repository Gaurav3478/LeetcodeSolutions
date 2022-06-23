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
    long int findPathSum(TreeNode *node, long int curSum, long int target) {
        if(!node) {
            return 0;
        }
        long int current = curSum + node->val;
        return (current==target) + findPathSum(node->left, current, target) + findPathSum(node->right, current, target);
    }
    
    long int pathSum(TreeNode* root, int targetSum) {
        //I want the path sum starting at each node, if it is a valid node
        if(root == NULL) {
            return 0;
        }
        return findPathSum(root, 0, targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
    } 
};