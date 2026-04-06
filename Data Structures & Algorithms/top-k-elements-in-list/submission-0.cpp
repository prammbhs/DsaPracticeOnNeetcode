class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int num:nums) {
            if(!mp.count(num)) {
                mp[num]=1;
            }else {
                mp[num]++;
            }
        }
        vector<vector<int>> bucket(nums.size()+1);
        for(auto& [num,freq]: mp) {
            bucket[freq].push_back(num);
        }
        vector<int> ans;
        for(int i=nums.size();i>0 && ans.size()<k;i--) {
            for(auto num: bucket[i]) {
                
                ans.push_back(num);
                if(ans.size()==k) {
                    return ans;
                }
                
            }
        }
        return ans;
    }
};
