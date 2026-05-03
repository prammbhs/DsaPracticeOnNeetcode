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
    int count;
    void dfs(TreeNode* root,int maxval) {
        if(!root) {
            return;
        }
        if(maxval<=root->val) {
            maxval = root->val;
            count++;
        }
        dfs(root->left,maxval);
        dfs(root->right,maxval);
    }
public:
    int goodNodes(TreeNode* root) {
        count=0;
        dfs(root,-101);
        return count;
    }
};
