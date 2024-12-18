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

struct node {
    int num;
    int time;
};

int t;
vector<int> v;
vector<vector<int>> dat;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int target;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, k;
        cin >> n >> k;
        v.clear();
        dat.clear();
        v.resize(n+1);
        for (int j = 1; j <= n; j++) {
            cin >> v[j];
        }
        dat.resize(n + 1, vector<int>());
        for (int j = 0; j < k; j++) {
            int from, to;
            cin >> from >> to;
            dat[to].push_back(from);
        }
        cin >> target;
        queue<node> q; // pq를 쓰면 오히려 log 만큼의 시간이 더 걸린다
        vector<int> visited(n + 1, 0);

        q.push({ target, v[target] });

        int ans = 0;
        while (!q.empty()) {
            node now = q.front();
            q.pop();
            ans = max(ans, now.time);

            // 이미 q에 들어있는 항목들은 아래 반복문 visited에서 걸러지지 않을 수 있음
            if (now.time < visited[now.num]){continue;};

            for (int j = 0; j < dat[now.num].size(); j++) {
                int next_num = dat[now.num][j];
                int next_time = now.time + v[next_num];

                if (visited[next_num] >= next_time) { continue; }
                visited[next_num] = next_time;

                q.push({ next_num, next_time });
            }
        }
        cout << ans << "\n";
    }
}

/*
1번 예제 기준
{4, 10}
{2, 21} {3, 110}
{1, 22} {1, 120}
이런 식으로 그 다음 노드로 갈때 시간을 누적하여 가장 큰 시간을 구한다.
*/