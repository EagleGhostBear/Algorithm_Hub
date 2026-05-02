class Solution {
public:
    int v1[7] = {0, 1, 2, 5, 6, 8, 9};
    int v2[3] = {0, 1, 8};
    void solve1(unordered_map<int, bool>& um, int len, int num){
        if(len == 0){
            um[num] = true;
            return;
        }
        for(int i=0; i<7; i++){
            solve1(um, len - 1, num * 10 + v1[i]);
        }
    }
    void solve2(unordered_map<int, bool>& um, int len, int num){
        if(len == 0){
            um[num] = false;
            return;
        }
        for(int i=0; i<3; i++){
            solve2(um, len - 1, num * 10 + v2[i]);
        }
    }
    int rotatedDigits(int n) {
        if(n == 10000) n-= 1;
        int ans = 0, len = to_string(n).size();
        for(int sz=1; sz<len; sz++){
            int cnt = 6, minus = 2;
            for(int i=1; i<sz; i++){
                cnt *= 7;
                minus *= 3;
            }
            ans += cnt - minus;
        }
        unordered_map<int, bool> um;
        for(int i=1; i<7; i++) solve1(um, len - 1, v1[i]);
        for(int i=1; i<3; i++) solve2(um, len - 1, v2[i]);
        for(auto c : um) if(c.second && n >= c.first) ans++;
        return ans;
    }
};
/*
1자리 - 4자리 까지의 수
1. 2, 5, 6, 9 = 반드시 포함
2. 1번이 만족한다면 나머지에 8,1,0 올 수 있음
*/