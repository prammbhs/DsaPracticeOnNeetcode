class Solution {
    void dfs(auto& num,int idx,auto& res,vector<int>& subset) {
        if(idx>=num.size()) {
            res.push_back(subset);
            return;
        }
        subset.push_back(num[idx]);
        dfs(num,idx+1,res,subset);
        subset.pop_back();
        dfs(num,idx+1,res,subset);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        dfs(nums,0,res,subset);
        return res;
    }
};
