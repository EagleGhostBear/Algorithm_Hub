class Solution {
public:
    string addBinary(string a, string b) {
        int sz = max(a.size(), b.size());
        string ret = "";
        int upVal = 0;
        for(int i=0; i<sz; i++){
            int aIdx = a.size() - 1 - i;
            int bIdx = b.size() - 1 - i;
            int aVal = (aIdx >= 0 ? a[aIdx] - '0' : 0);
            int bVal = (bIdx >= 0 ? b[bIdx] - '0' : 0);
            int now = upVal + aVal + bVal;
            upVal = 0;
            if(now > 1){
                upVal = 1;
                now -= 2;
            }
            ret = to_string(now) + ret;
        }
        if(upVal) ret = "1" + ret;
        return ret;
    }
};