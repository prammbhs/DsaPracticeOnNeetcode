class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) {
            return false;
        }
        int k = s1.size();
        unordered_map<char,int> key;
        for(int i=0;i<k;i++) {
            key[s1[i]]++;
        }
        unordered_map<char,int> val;
        for(int i=0;i<k;i++) {
            val[s2[i]]++;
        }
        if(key==val) {
            return true;
        }
        for(int i=k;i<s2.size();i++) {
            val[s2[i-k]]--;
            if(val[s2[i-k]]==0) {
                val.erase(s2[i-k]);
            }
            val[s2[i]]++;
            if(key==val) {
                return true;
            }
        }
        return false;
    }
};
