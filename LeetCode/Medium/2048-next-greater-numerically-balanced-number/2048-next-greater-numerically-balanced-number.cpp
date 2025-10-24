map<int, bool> m;

void sel_num(vector<int>& gp, vector<int> cnt, vector<int>& tmp){
    bool chk = true;
    for(auto n : cnt) if(n) chk = false;
    if(chk){
        int val = tmp[0];
        for(int i=1; i<tmp.size(); i++) val = (val * 10) + tmp[i];
        m[val] = true;
        return;
    }

    int idx = 0;
    for(int i=0; i<cnt.size(); i++) if(cnt[i]) {idx = i; break;}
    for(int i=0; i<tmp.size(); i++){
        if(tmp[i]) continue;
        tmp[i] = gp[idx];
        cnt[idx]--;
        sel_num(gp, cnt, tmp);
        cnt[idx]++;
        tmp[i] = 0;
    }
    return;
}

// 해당 숫자 조합으로 만들 수 있는 숫자 반환
void find_com(vector<int>& gp, int len){
    vector<int> tmp(len, 0);
    sel_num(gp, gp, tmp); // gp[0]에 해당 하는 숫자 개수만큼 조합
    return;
}

// 해당 자리수로 만들 수 있는 숫자 조합 반환
void find_num(int len, int prev, vector<int> tmp, vector<vector<int>>& gp){
    if(len == 0){
        gp.push_back(tmp);
        return;
    }

    for(int i=prev + 1; i<=len; i++){
        tmp.push_back(i);
        find_num(len - i, i, tmp, gp);
        tmp.pop_back();
    }
    return;
}

void solve(int len){ // 해당 자리수를 이루는 숫자 조합 파악
    vector<vector<int>> gp;
    find_num(len, 0, {}, gp);
    for(int i=0; i<gp.size(); i++){
        find_com(gp[i], len);
    }
    return;
}

class Solution {
public:
    int nextBeautifulNumber(int n) {
        m.clear();
        int sz = to_string(n).size();
        for(int i=sz; i<=7; i++) solve(i);

        int ans = 0;
        for(auto c : m) if(c.first > n){ans = c.first; break;}
        return ans;
    }
};
/*
0은 절대 나오면 안됨
0, 8, 9 는 못나옴
최소 1자리 <= 1,000,000 <= 최대 7자리, 그럼 7자리까지 확인해야함
7
6, 1
5, 2
4, 3
1, 2, 4
---
6
5, 1
4, 2
1, 2, 3 = 3자리
---
5
4, 1
3, 2
---
4
3, 1
---
3
2, 1
---
2
---
1
*/