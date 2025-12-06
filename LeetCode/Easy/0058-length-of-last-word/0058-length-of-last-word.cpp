class Solution {
public:
    int lengthOfLastWord(string s) {
        string tmp = "";
        int i = s.size() - 1;
        for(; i>-1; i--){
            if(s[i] == ' ') continue;
            else break;
        }
        for(; i>-1; i--){
            if(s[i] == ' ') break;
            else tmp += s[i];
        }
        return tmp.size();
    }
};