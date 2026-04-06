class Solution {

public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int left =0;
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<k;i++) {
            pq.push({nums[i],i});
        }
        ans.push_back(pq.top().first);
        for(int right = k;right<nums.size();right++) {
            left++;
            pq.push({nums[right],right});
            while(pq.top().second<left) {
                pq.pop();
            }
            ans.push_back(pq.top().first);
        }
        return ans;
    }
};
