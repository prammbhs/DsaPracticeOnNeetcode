class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> mp;
        mp[')'] = '(';
        mp[']'] = '[';
        mp['}'] = '{';
        stack<char> st;
        for(auto ch: s) {
            if(!mp.count(ch)) {
                st.push(ch);
            }else {
                if(st.empty()) {
                    return false;
                }
                if(st.top()==mp[ch]) {
                    st.pop();
                }else {
                    return false;
                }
            }
        }
        if(st.size()) {
            return false;
        }
        return true;
    }
};
