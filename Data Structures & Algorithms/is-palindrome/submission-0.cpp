class Solution {
public:
    bool isPalindrome(string s) {
        string temp = "";
        for(auto ch: s) {
            if(isalnum(ch)) {
                temp +=tolower(ch);
            }
        }
        string temp2 = temp;
        reverse(temp2.begin(),temp2.end());
        cout<<temp<<" "<<temp2;
        return temp==temp2;
    }
};
