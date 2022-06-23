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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) {
            return ans;
        }
        queue<TreeNode *> Q;
        Q.push(root);
        int curLevel = 0;
        while(!Q.empty()) {
            int sz = Q.size();
            vector<int> tmp(sz);
            for(int i=0; i<sz; i++) {
                TreeNode *node = Q.front();
                Q.pop();
                if(curLevel%2) {
                    tmp[sz - 1 - i] = node->val;
                }
                else {
                    tmp[i] = node->val;
                }
                if(node->left) {
                    Q.push(node->left);
                }
                if(node->right) {
                    Q.push(node->right);
                }
            }
            ans.push_back(tmp);
            curLevel++;
        }
        return ans;
    }
};