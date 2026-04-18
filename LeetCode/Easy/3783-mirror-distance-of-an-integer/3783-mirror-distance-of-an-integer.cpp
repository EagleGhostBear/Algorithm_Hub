class Solution {
public:
    int mirrorDistance(int n) {
        string s = to_string(n);
        int sz = s.size() / 2;
        for(int i=0; i<sz; i++){
            char tmp = s[i];
            s[i] = s[s.size() - 1 - i];
            s[s.size() - 1 - i] = tmp;
        }
        return abs(stoi(s) - n);
    }
};