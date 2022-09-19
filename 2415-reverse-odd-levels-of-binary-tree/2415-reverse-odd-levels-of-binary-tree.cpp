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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode *> Q;
        Q.push(root);
        int level = 0;
        vector<int> vals;
        while(!Q.empty()) {
            vector<int> vect;
            int sz = Q.size();
            for(int i=0; i<sz; i++) {
                TreeNode *node = Q.front();
                Q.pop();
                if(level%2) {
                    node->val = vals[sz - i - 1];
                }
                if(node->left) {
                    Q.push(node->left);
                    vect.push_back(node->left->val);
                }
                if(node->right) {
                    Q.push(node->right);
                    vect.push_back(node->right->val);
                }
            }
            level++;
            vals = vect;
        }
        return root;
    }
};