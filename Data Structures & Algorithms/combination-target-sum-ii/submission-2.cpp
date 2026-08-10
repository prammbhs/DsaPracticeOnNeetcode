class Solution {
    void solve(auto& candidates,int idx,int target,auto& res,auto& subset) {
        if(target==0) {
            res.push_back(subset);
            return;
        }
        if(target<0 || idx>=candidates.size()) {
            return;
        }
        for(int i=idx;i<candidates.size();i++) {
            if(i>idx && candidates[i]==candidates[i-1]) {
                continue;
            }
            if(candidates[i]>target) {
                break;
            }
            subset.push_back(candidates[i]);
            solve(candidates,i+1,target-candidates[i],res,subset);
            subset.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> res;
        vector<int> subset;
        solve(candidates,0,target,res,subset);
        return res;
    }
};
