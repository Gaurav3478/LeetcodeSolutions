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

/*
ll dfs(ll v) {
    ll mn = c[v];
    vis[v] = true;
    for(ll x: adj[v]) {
        if(!vis[x]) {
            mn = min(mn, dfs(x));
        }
    }
    return mn;
}
*/

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL) {
            return 0;            
        }
        queue<TreeNode *> q;
        q.push(root);
        int depth = 1;
        while(!q.empty()) {
            int n = q.size();
            for(int i=0; i<n; i++) {
                TreeNode *t = q.front();
                if(t->left == NULL && t->right == NULL) {
                    return depth;
                }
                q.pop();
                if(t->left) {
                    q.push(t->left);
                }
                if(t->right) {
                    q.push(t->right);
                }
            }
            depth++;
        }
        return -1;
    }
};