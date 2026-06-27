class Solution {
public:
    bool isPalindrome(string s) {
       
        string r="";
        for (char ch : s){
            if (isalnum(ch)){
                 r+=tolower(ch);
            }
        }
        string rev = r;
        reverse(rev.begin(), rev.end());

        return r == rev;
    }
};
