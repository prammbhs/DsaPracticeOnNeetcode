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

    void dfs(TreeNode* root,int& k,vector<int>& ans) {
        if(!root||(ans.size()==k)) {
            return;
        }
        dfs(root->left,k,ans);
        ans.push_back(root->val);
        dfs(root->right,k,ans);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans;
        dfs(root,k,ans);
        return ans[k-1];
    }
};
