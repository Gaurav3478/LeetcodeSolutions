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
    void findPathSum(TreeNode *node, vector<int> &path, vector<vector<int>> &paths, int targetSum) {
        if(!node) {
            return;
        }
        path.push_back(node->val);
        if(node->left == NULL && node->right == NULL && targetSum == node->val) {
            paths.push_back(path);
        }
        findPathSum(node->left, path, paths, targetSum - node->val);
        findPathSum(node->right, path, paths, targetSum - node->val);
        path.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> paths;
        vector<int> path;
        findPathSum(root, path, paths, targetSum);
        return paths;
    }
};