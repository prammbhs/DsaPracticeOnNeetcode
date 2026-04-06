class Solution {
    bool caneat(vector<int>& piles,int h,int k) {
        long long time = 0;
        for(auto pile:piles) {
            time +=(pile+k-1)/k;
        }
        return time<=h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int minrate = INT_MAX;
        int left  = 1;
        int right = *max_element(piles.begin(),piles.end());
        while(left<=right) {
            int mid = left+(right-left)/2;
            if(caneat(piles,h,mid)) {
                minrate = mid;
                right = mid-1;
            }else {
                left = mid+1;
            }
        }
        return minrate; 
    }
};
