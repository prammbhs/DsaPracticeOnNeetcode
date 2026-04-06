class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s=="") {
            return 0;
        }
        int  l=0;
        unordered_map<char,int> seen;
        int maxlen = 1;
        seen[s[0]]=0;
        for(int r=1;r<s.size();r++) {
            if(seen.count(s[r])) {
                l  =max(seen[s[r]]+1,l);
            }
            seen[s[r]]=r;
            maxlen = max(maxlen,r-l+1);
        }
        return maxlen;
    }
};
