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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)   return {};
        queue<TreeNode*> nodes;
        nodes.push(root);
        vector<vector<int>> ans;
        while(nodes.size()) {
            int size = nodes.size();
            vector<int> level(size,0);
            for(int i=0;i<size;i++) {
                TreeNode* currnode = nodes.front();
                nodes.pop();
                level[i] = currnode->val;
                if(currnode->left) {
                    nodes.push(currnode->left);
                }
                if(currnode->right) {
                    nodes.push(currnode->right);
                }
            }
            ans.push_back(level);
        }
        return ans;
    }
};
