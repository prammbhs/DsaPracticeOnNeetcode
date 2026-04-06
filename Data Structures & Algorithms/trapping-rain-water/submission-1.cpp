class Solution {
public:
    int trap(vector<int>& height) {
        // int l=0;
        // int r=height.size()-1;
        // int lmax=0;
        // int rmax = 0;
        // int water = 0;
        // while(l<r) {
        //     if(height[l]<height[r]) {
        //         if(lmax<=height[l]) {
        //             lmax = height[l];
        //         }else {
        //             water += (lmax-height[l]);
        //         }
        //         l++;
        //     }else {
        //         if(rmax<=height[r]) {
        //             rmax = height[r];
        //         }else {
        //             water += rmax-height[r];
        //         }
        //         r--;
        //     }
        // }
        // return water;
        stack<int> st;
        int water = 0;
        for(int i=0;i<height.size();i++) {
            while(st.size() && height[st.top()]<height[i]) {
                int mid = st.top();
                st.pop();
                if(st.empty()) {
                    break;
                }
                int l = st.top();
                int width = i-l-1;
                int h = min(height[l],height[i])-height[mid];
                water += (h*width);
            }
            st.push(i);
        }
        return water;
    }
};
