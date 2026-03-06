class Solution {
public:
    bool checkOnesSegment(string s) {
        int endIdx = s.size() - 1;
        for(; endIdx>-1; endIdx--) if(s[endIdx] - '0') break;
        for(int i=1; i<=endIdx; i++){
            if(s[i] - '0' == 0) return false;
        }
        return true;
    }
};