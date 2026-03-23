class Solution {
public:
    bool isPalindrome(string s) {
        string ans = "";
        for(auto c : s){
            if('a' <= c && c <= 'z') ans += c;
            else if('0' <= c && c <= '9') ans += c;
            else if('A' <= c && c <= 'Z') ans += c + 32;
        }
        int sz = ans.size() / 2;
        for(int i=0; i<sz; i++) if(ans[i] != ans[ans.size() - 1 - i]) return false;
        return true;
    }
};