class Solution {
public:
    string solve(string s){
        string ret = s;
        int sz = s.size();
        for(int i=0; i<sz / 2; i++){
            char tmp = (ret[i] == '0' ? '1' : '0');
            ret[i] = (ret[sz - 1 - i] == '0' ? '1' : '0');
            ret[sz - 1 - i] = tmp;
        }
        if(sz % 2) ret[sz / 2] = (ret[sz / 2] == '0' ? '1' : '0');
        return s + '1' + ret;
    }
    char findKthBit(int n, int k) {
        string s = "0";
        for(int i=0; i<n; i++) s = solve(s);
        return s[k - 1];
    }
};