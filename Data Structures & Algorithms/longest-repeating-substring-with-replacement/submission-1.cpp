class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> freq;
        int l=0;
        int maxlen=1;
        int maxfreq = 1;
        freq[s[0]]=1;
        for(int r = 1;r<s.size();r++) {
            freq[s[r]]++;
            maxfreq = max(maxfreq,freq[s[r]]);
            int size = r-l+1;
            if(size-maxfreq >k) {
                freq[s[l]]--;
                l++;
            }
            maxlen = max(maxlen,r-l+1);
        }
        return maxlen;
    }
};
