class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";
        for(auto s: strs) {
            ans += (s+'-');
        }
        return ans;
    }

    vector<string> decode(string s) {
        stringstream ss(s);
        vector<string> ans;
        string word;
        while(getline(ss,word,'-')) {
            ans.push_back(word);
        }
        return ans;
    }
};
