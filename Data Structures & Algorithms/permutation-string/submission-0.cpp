class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k = s1.size();
        sort(s1.begin(),s1.end());
        for(int i=0;i<s2.size()-k+1;i++) {
            string temp = s2.substr(i,k);
            sort(temp.begin(),temp.end());
            cout<<temp;
            if(temp==s1) {
                return true;
            }
        }
        return false;
    }
};
