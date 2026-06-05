class Solution {
public:
    int myAtoi(string s) {
        int idx = 0, intMax = ((long long)1 << 31) - 1;
        bool pm = true; // 양수
        // 공백제거
        for(; idx<s.size(); idx++) if(s[idx] != ' ') break;
        if(idx >= s.size()) return 0;
        // 부등호 제거
        if(s[idx] == '+') idx++;
        else if(s[idx] == '-') {idx++; pm = false;}
        // 의미없는 0제거
        for(; idx<s.size(); idx++) if(s[idx] != '0') break;
        // 불필요한 뒷부분 자르기
        int len = 0;
        for(; len+idx<s.size(); len++) if(s[len + idx] < '0' || '9' < s[len + idx]) break;
        string ns = s.substr(idx, len);
        if(ns.size() == 0) return 0;

        // int 범위 넘어가는지 확인
        if(ns.size() > 10){
            if(pm) return intMax;
            else return -intMax-1;
        }

        long long num = (pm ? stoll(ns) : -1 * stoll(ns));
        if(num > intMax) return intMax;
        else if(num < -intMax-1) return -intMax-1;

        return (int)num;
    }
};