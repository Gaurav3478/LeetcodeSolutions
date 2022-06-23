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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode *> Q;
        Q.push(root);
        vector<vector<int>> ans;
        if(!root) {
            return ans;
        }
        while(!Q.empty()) {
            int sz = Q.size();
            vector<int> cur;
            for(int i=0; i<sz; i++) {
                TreeNode *node = Q.front();
                Q.pop();
                cur.push_back(node->val);
                if(node->left) {
                    Q.push(node->left);
                }
                if(node->right) {
                    Q.push(node->right);
                }
            }
            ans.push_back(cur);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};