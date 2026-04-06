class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxarea = 0;
        int n = heights.size();
        int l=0;
        int r=n-1;
        while(l<r) {
            int h = min(heights[l],heights[r]);
            int width = r-l;
            maxarea = max(maxarea,h*width);
            if(heights[l]<heights[r]) {
                l++;
            } else {
                r--;
            }
        }
        return maxarea;
    }
};
