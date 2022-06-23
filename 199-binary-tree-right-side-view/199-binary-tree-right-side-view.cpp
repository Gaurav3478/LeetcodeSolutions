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
    vector<int> rightSideView(TreeNode* root) {
        //return list of all rightmost nodes
        //in each level find rightmost node
        vector<int> ans;
        if(!root) {
            return ans;
        }
        queue<TreeNode *> Q;
        Q.push(root);
        while(!Q.empty()) {
            int sz = Q.size();
            for(int i=0; i<sz; i++) {
                TreeNode *node = Q.front();
                if(i == sz-1) {
                    ans.push_back(node->val);
                }
                Q.pop();
                if(node->left) {
                    Q.push(node->left);
                }
                if(node->right) {
                    Q.push(node->right);
                }
            }
        }
        return ans;
    }
};