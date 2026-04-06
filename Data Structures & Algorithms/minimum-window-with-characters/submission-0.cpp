class Solution {
public:
    string minWindow(string s, string t) {

        if(t.size() > s.size()) return "";

        unordered_map<char,int> need;
        for(char c : t) need[c]++;

        unordered_map<char,int> window;

        int required = need.size();
        int formed = 0;

        int l = 0;
        int minLen = INT_MAX;
        int start = 0;

        for(int r = 0; r < s.size(); r++) {

            char c = s[r];
            window[c]++;

            if(need.count(c) && window[c] == need[c])
                formed++;

            while(formed == required) {

                if(r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }

                window[s[l]]--;

                if(need.count(s[l]) && window[s[l]] < need[s[l]])
                    formed--;

                l++;
            }
        }

        if(minLen == INT_MAX) return "";

        return s.substr(start, minLen);
    }
};