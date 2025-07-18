#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

int r, c;
int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };
int v[1500][1500];
bool visited[1500][1500]; // 얼음 방문 여부 확인
queue<int> duck, ice;

bool is_connect() {
    while (duck.size()) {
        int row = duck.front() / c;
        int col = duck.front() % c;
        duck.pop();

        for (int i = 0; i < 4; i++) {
            int nr = row + dr[i];
            int nc = col + dc[i];
            if (nr < 0 || nc < 0 || nr >= r || nc >= c) continue;
            if (v[nr][nc] == 2) continue; // 이미 오리가 방문했으면 생략

            int idx = nr * c + nc;
            if (v[nr][nc] == 0) { // 미방문 호수
                v[nr][nc] = 2;
                duck.push(idx);
            }
            //else if (v[nr][nc] == 1) next.push(idx); // 얼음이 다음턴에 녹기 때문
            else if (v[nr][nc] == 3) return false;
        }
    }
    return true;
}

void init_ice(int row, int col) { // 최초 녹을 얼음들을 추가
    for (int i = 0; i < 4; i++) {
        int nr = row + dr[i];
        int nc = col + dc[i];
        if (nr < 0 || nc < 0 || nr >= r || nc >= c) continue;
        if (visited[nr][nc]) continue;

        if (v[nr][nc] == 1) {
            visited[nr][nc] = true;
            ice.push(nr * c + nc);
        }
    }
    return;
}

bool is_side(int row, int col) {
    for (int i = 0; i < 4; i++) {
        int nr = row + dr[i];
        int nc = col + dc[i];
        if (nr < 0 || nc < 0 || nr >= r || nc >= c) continue;
        if (v[nr][nc] == 2) return true;
    }
    return false;
}

void is_melt() { // 얼음을 녹임
    queue<int> next;
    while (ice.size()) {
        int row = ice.front() / c;
        int col = ice.front() % c;
        ice.pop();

        v[row][col] = 0;
        if (is_side(row, col)) v[row][col] = 2, duck.push(row * c + col);
        for (int i = 0; i < 4; i++) {
            int nr = row + dr[i];
            int nc = col + dc[i];
            if (nr < 0 || nc < 0 || nr >= r || nc >= c || visited[nr][nc]) continue;
            int idx = nr * c + nc;
            if (v[nr][nc] == 1) {
                visited[nr][nc] = true;
                next.push(idx); // 녹은 얼음과 인접한 얼음들은 다음 순번에 녹음
            }
        }
    }
    ice = next;
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> r >> c;
    int val = 2;
    for (int i = 0; i < r; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < c; j++) {
            if (s[j] == 'X') v[i][j] = 1; // 얼음 : 1
            else if (s[j] == 'L') { // 오리 : 2, 3
                v[i][j] = val++;
                if (v[i][j] == 2) duck.push(i * c + j);
            }
            else v[i][j] = 0; // 호수 : 0
        }
    }

    for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) if (v[i][j] != 1) init_ice(i, j);

    int ans = 0;
    while (is_connect()) {
        is_melt();
        ans++;
    }
    cout << ans;
}