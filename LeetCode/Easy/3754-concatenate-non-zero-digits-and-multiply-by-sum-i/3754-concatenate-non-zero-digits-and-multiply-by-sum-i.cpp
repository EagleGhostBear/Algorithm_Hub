class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0, s = 0;
        string num = to_string(n);
        for(auto c : num){
            if(c == '0') continue;
            x = x * 10 + c - '0';
            s += c - '0';
        }
        return x * s;
    }
};