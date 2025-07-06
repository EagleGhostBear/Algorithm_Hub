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

int t, h, w, ans = 0;
bool find_key = false;
vector<int> key;
vector<vector<pair<int, int>>> door;
vector<vector<int>> v;
queue<pair<int, int>> q;

bool is_open(int row, int col) { // 탐색하다 발견한 경우
    if (v[row][col] == 1) return false; // 벽

    if (v[row][col] == -1) ans++; // 문서
    else if ('A' <= v[row][col] && v[row][col] <= 'Z') { // 문
        if (key[v[row][col] - 'A'] == 0) { // 열쇠 없을때
            door[v[row][col] - 'A'].push_back({row, col});
            v[row][col] = 1; // 따로 보관할것이기 때문에 중복 검사를 피하기 위해
            return false;
        }
    }
    else if ('a' <= v[row][col] && v[row][col] <= 'z') { // 열쇠
        key[v[row][col] - 'a'] = 1;
        find_key = true;
    }
    v[row][col] = 1;
    q.push({ row, col });
    return true;
}

void bfs() {
    int dr[] = { -1, 0, 1, 0 };
    int dc[] = { 0, 1, 0, -1 };
    while (q.size()) {
        pair<int, int> now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = now.first + dr[i];
            int nc = now.second + dc[i];
            if (nr < 0 || nc < 0 || nr >= h || nc >= w) continue;
            if (is_open(nr, nc)) {
                q.push({ nr, nc });
            }
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while (t--) {
        cin >> h >> w;
        string s;
        ans = 0;
        key.assign(26, 0);
        door.assign(26, vector<pair<int, int>>(0, pair<int, int>()));
        v.assign(h, vector<int>(w, 0));
        find_key = false;
        for (int i = 0; i < h; i++) {
            cin >> s;
            for (int j = 0; j < w; j++) {
                if (s[j] == '*') v[i][j] = 1; // 벽
                else if (s[j] == '$') v[i][j] = -1; // 문서
                else if (s[j] == '.') v[i][j] = 0; // 빈공간
                else v[i][j] = int(s[j]); // 문(65 - 90) or 열쇠(97 - 122)
            }
        }
        cin >> s;
        if (s != "0") {
            for (auto c : s) key[c - 'a'] = 1;
            find_key = true;
        }
        for (int i = 0; i < w; i++) {
            if (is_open(0, i)) bfs();
            if (is_open(h-1, i)) bfs();
        }
        for (int i = 0; i < h; i++) {
            if (is_open(i, 0)) bfs();
            if (is_open(i, w-1)) bfs();
        }
        while (find_key) { // 만약 새로 찾은 열쇠가 있는 경우 계속 열수 있는 문이 있는지 확인
            for (int i = 0; i < 26; i++) {
                for (int j = door[i].size() - 1; j > -1; j--) {
                    if (key[i]) {
                        int row = door[i][j].first;
                        int col = door[i][j].second;
                        door[i].pop_back();
                        q.push({ row, col });
                    }
                }
            }
            find_key = false;
            bfs();
        }
        cout << ans << "\n";
    }
}