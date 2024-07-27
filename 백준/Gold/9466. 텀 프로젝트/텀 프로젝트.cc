#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct node {
    bool chk_team = false; // 이미 팀을 이루었는지
    int team_num = 0;
    int target;
    int pick_cnt = 0;
};

int t, n;
int total = 0;
vector<node> v;
vector<int> path;

void bfs(int now) {
    int next = v[now].target;
    if (v[next].chk_team) {
        if (v[now].team_num == next) { // 루프 완성
            return;
        }
        else {
            total += 1;
            for (auto i : path) {
                v[i].chk_team = false;
            }
            return;
        }
    }
    path.push_back(next);
    v[next].chk_team = true;
    v[next].team_num = v[now].team_num;
    bfs(next);
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> t;
    for (int k = 0; k < t; k++) {
        total = 0;
        cin >> n;
        v.clear();
        v.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            int tmp;
            cin >> tmp;
            v[i].target = tmp;
            v[tmp].pick_cnt += 1;
        }

        queue<node> q;
        for (int i = 1; i <= n; i++) {
            if (v[i].pick_cnt == 0) {
                q.push(v[i]);
            }
        }

        while (!q.empty()) {
            node now = q.front();
            q.pop();

            int target = now.target;
            v[target].pick_cnt -= 1;
            if (v[target].pick_cnt == 0) {
                q.push(v[target]);
            }
        }

        for (int i = 1; i <= n; i++) {
            if (v[i].pick_cnt == 0) {
                total += 1;
                continue;
            }
            if (v[i].chk_team) {
                continue;
            }
            path.clear();
            path.push_back(i);
            v[i].chk_team = true;
            v[i].team_num = i;
            bfs(i);
        }

        cout << total << "\n";
    }
}