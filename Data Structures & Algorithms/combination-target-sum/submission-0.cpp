class Solution {
    void countway(auto& nums,int idx,int target,auto& res,auto& subset) {
        if(target==0) {
            res.push_back(subset);
            return;
        }
        if(idx>=nums.size()||target<0) {
            return;
        }
        subset.push_back(nums[idx]);
        countway(nums,idx,target-nums[idx],res,subset);
        subset.pop_back();
        countway(nums,idx+1,target,res,subset);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> subset;
        countway(nums,0,target,res,subset);
        return res;
    }
};
