class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(auto s: strs) {
            string temp  = s;
            sort(temp.begin(),temp.end());
            if(mp.count(temp)) {
                mp[temp].push_back(s);
            }else {
                mp[temp]={s};
            }

        }
        vector<vector<string>> ans;
        for(auto& [key,arr]: mp) {
            ans.push_back(arr);
        }
        return ans;
    }
};
