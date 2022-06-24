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
    TreeNode *build(vector<int> &preorder, vector<int> &inorder, int &rootIdx, int l, int r) {
        if(l > r) {
            return NULL;
        }
        int inIdx;
        for(int i=l; i<=r; i++) {
            if(inorder[i] == preorder[rootIdx]) {
                inIdx = i;
                break;
            }
        }
        rootIdx++;
        return new TreeNode(inorder[inIdx], build(preorder, inorder, rootIdx, l, inIdx - 1), build(preorder, inorder, rootIdx, inIdx + 1, r));
        
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int rootIdx = 0;
        return build(preorder, inorder, rootIdx, 0, preorder.size()-1);
    }
};