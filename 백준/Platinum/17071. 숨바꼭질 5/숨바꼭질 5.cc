#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

int n, k;
int ans = 500001;
vector<vector<int>> v(500001, vector<int>(2, 500001)); // v[col][짝, 홀]

void bfs() {
    queue<pair<int, bool>> q; // loc, (짝, 홀)
    q.push({ n, false });

    int dc[] = { 0, -1, 1 };
    while (q.size()) {
        pair<int, bool> now = q.front();
        q.pop();

        for (int i = 0; i < 3; i++) {
            int nc = now.first + dc[i];
            if (i == 0) nc *= 2;
            if (nc < 0 || nc >= 500001) continue;
            if (v[nc][!now.second] > v[now.first][now.second] + 1) {
                v[nc][!now.second] = v[now.first][now.second] + 1;
                q.push({ nc, !now.second });
            }
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    v[n][0] = 0;

    bfs();

    int total = k;
    for (int i = 0; total + i <= 500000; i++) {
        total += i;
        if (v[total][i%2] <= i) ans = min(ans, i);
    }

    if (ans == 500001) cout << "-1";
    else cout << ans;
}
/*
짝, 홀 나눠야 하는 이유
if (v[nc] > v[now] + 1)
최단 경로를 갱신하는 과정에서 짝수 최단, 홀수 최단을 구분하지 않으면
동생이 짝수 시간에 도착했을때 짝수 최단, 홀수 시간에 도착했을때는 홀수 최단을 적용해야 하는데 불가능해진다.
*/