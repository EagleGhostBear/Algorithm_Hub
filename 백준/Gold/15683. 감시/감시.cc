#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <deque>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

int n, m, ans = 64;
vector<vector<int>> v, simul;
vector<pair<int, int>> cctv;

void simul_cctv(int level, int mode, int val) {
    pair<int, int> init_loc = cctv[level];
    int type = v[cctv[level].first][cctv[level].second];
    int dr[] = { -1,0,1,0 };
    int dc[] = { 0,1,0,-1 };
    vector<int> mv;
    if (type == 1) mv.push_back(0 + mode);
    else if (type == 2) {
        mv.push_back(0 + mode);
        mv.push_back(2 + mode);
    }
    else if (type == 3) {
        mv.push_back(0 + mode);
        mv.push_back((1 + mode) % 4);
    }
    else if (type == 4) {
        mv.push_back(0 + mode);
        mv.push_back((1 + mode) % 4);
        mv.push_back((2 + mode) % 4);
    }
    else if (type == 5) {
        mv.push_back(0);
        mv.push_back(1);
        mv.push_back(2);
        mv.push_back(3);
    }

    for (int i = 0; i < mv.size(); i++) {
        pair<int, int> now = init_loc;
        while (now.first >= 0 && now.second >=0 && now.first < n && now.second < m && v[now.first][now.second] != 6) {
            simul[now.first][now.second] += val;
            now.first += dr[mv[i]];
            now.second += dc[mv[i]];
        }
    }
    return;
}

void solution(int level) {
    if (level == -1) {
        int cnt = 0;
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (!simul[i][j]) cnt++;
        ans = min(ans, cnt);
        return;
    }

    int type = v[cctv[level].first][cctv[level].second];
    if (type == 2) for (int i = 0; i < 2; i++) {
        simul_cctv(level, i, 1);
        solution(level - 1);
        simul_cctv(level, i, -1);
    }
    else if (type == 5) {
        simul_cctv(level, 0, 1);
        solution(level - 1);
        simul_cctv(level, 0, -1);
    }
    else {
        for (int i = 0; i < 4; i++) {
            simul_cctv(level, i, 1);
            solution(level - 1);
            simul_cctv(level, i, -1);
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    v.resize(n, vector<int>(m));
    simul.resize(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        cin >> v[i][j];
        if (v[i][j] == 6) simul[i][j] = 1;
        else if (v[i][j] != 0) cctv.push_back({ i, j });
    }

    solution(cctv.size() - 1);
    cout << ans;
}