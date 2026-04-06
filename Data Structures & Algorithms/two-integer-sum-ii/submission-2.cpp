class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size()-1;
        
        while(l<r) {
            int currsum = nums[l]+nums[r];
            if(currsum==target) {
                return{l+1,r+1};
            }else if(currsum>target) {
                r--;
            }else {
                l++;
            }

        }
        return {};
    }

};
