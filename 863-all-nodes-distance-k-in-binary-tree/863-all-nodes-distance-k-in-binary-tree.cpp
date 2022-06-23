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
    map<TreeNode *, TreeNode *> par;
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        //first find all parent nodes and store
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
                Q.pop();
                if(node->left) {
                    par[node->left] = node;
                    Q.push(node->left);
                }
                if(node->right) {
                    par[node->right] = node;
                    Q.push(node->right);
                }
            }
        }
        //now do a BFS from target node
        unordered_map<TreeNode *, bool> vis;
        assert(Q.empty());
        Q.push(target);
        vis[target] = true;
        int cur_distance = 0;
        while(!Q.empty()) {
            if(cur_distance == k) {
                break;
            }
            cur_distance++;
            int sz = Q.size();
            for(int i=0; i<sz; i++) {
                TreeNode *node = Q.front();
                Q.pop();
                if(node->left && !vis[node->left]) {
                    vis[node->left] = true;
                    Q.push(node->left);
                }
                if(node->right && !vis[node->right]) {
                    vis[node->right] = true;
                    Q.push(node->right);
                }
                TreeNode *p = par[node];
                if(p && !vis[p]) {
                    vis[p] = true;
                    Q.push(p);
                }
            }
        }
        while(!Q.empty()) {
            auto x = Q.front();
            Q.pop();
            ans.push_back(x->val);
        }
        return ans;
    }
};