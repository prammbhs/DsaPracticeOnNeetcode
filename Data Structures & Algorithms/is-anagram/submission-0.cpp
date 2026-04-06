class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> alpha(26,0);
        for(auto ch: s) {
            alpha[ch-'a']++;
        }
        for(auto ch: t) {
            if(alpha[ch-'a']<=0) {
                return false;
            }
            alpha[ch-'a']--;
        }
        for(auto num: alpha) {
            if(num>0) {
                return false;
            }
        }
        return true;
    }
};
