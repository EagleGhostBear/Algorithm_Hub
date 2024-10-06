#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct node {
    int s; // 내구도
    int w; // 무게
};

int n;
int cnt = 0;
int maxv = 0;
vector<node> v;

void sol(int idx) { // idx = 손에 든 계란
    if (idx == n) { // 모든 계란 확인 완료
        return;
    }

    for (int i = 0; i < n; i++) { // 대상 계란 선택
        if (v[idx].s <= 0) { sol(idx + 1); }
        else if (idx == i || v[i].s <= 0) { continue; } // 손에 든것과 같거나, 공격 대상이 이미 깨져 있으면 생략
        else {
            v[idx].s -= v[i].w;
            v[i].s -= v[idx].w;
            if (v[idx].s <= 0) { cnt++; }
            if (v[i].s <= 0) { cnt++; }
            maxv = max(maxv, cnt);
            sol(idx + 1); // 오른쪽 계란 선택
            if (v[idx].s <= 0) { cnt--; }
            if (v[i].s <= 0) { cnt--; }
            v[idx].s += v[i].w;
            v[i].s += v[idx].w;
        }
    } // 2번을 들고 있는데 나머지가 모두 깨져버린 상황에서는 다음번으로 가지 못한다.
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n; // 최대 8
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].s >> v[i].w;
    }

    sol(0); // 가장 왼쪽 계란 선택

    cout << maxv;
}