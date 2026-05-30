class Solution {
public:
    int reverse(int x) {
        string s = to_string(x);
        if(s[0] == '-') s = s.substr(1);
        int hf = s.size()/2;
        for(int i=0; i<hf; i++){
            char tmp = s[i];
            s[i] = s[s.size() - 1 - i];
            s[s.size() - 1 - i] = tmp;
        }
        long long ans = stoll(s);
        if(x < 0) ans *= -1;
        if(ans < -((long long)1 << 31) || ans > ((long long)1 << 31) - 1) return 0;
        return (int)ans;
    }
};