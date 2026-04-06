class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<int> st;
        vector<int> ans(temp.size(),0);
        for(int i=0;i<temp.size();i++) {
            while(st.size() && temp[st.top()]<temp[i]) {
                int left = st.top();
                st.pop();
                ans[left] = i-left;
            }
            st.push(i);
        }
        return ans;
    }
};
