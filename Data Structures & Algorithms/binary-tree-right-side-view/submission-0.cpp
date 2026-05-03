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
        if(!root)   return {};
        unordered_map<int,int> mp;
        queue<pair<int,TreeNode*>> nodes;
        nodes.push({0,root});
        while(!nodes.empty()) {
            auto [level,curr] = nodes.front();
            nodes.pop();
            mp[level]=curr->val;
            if(curr->left) {
                nodes.push({level+1,curr->left});
            }
            if(curr->right) {
                nodes.push({level+1,curr->right});
            }
        }
        vector<int> ans(mp.size(),0);
        for(auto it: mp) {
            ans[it.first]=it.second;
        }
        return ans;
    }
};
