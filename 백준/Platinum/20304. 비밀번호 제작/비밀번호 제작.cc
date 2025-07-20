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

int n, m, ans = 0;
vector<int> visited;
queue<int> q;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    visited.resize(n + 1, -1); // 방문하지 않은 값 : -1
    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;
        visited[num] = 0;
        q.push(num);
    }

    while (q.size()) {
        int now = q.front();
        q.pop();

        for (int i = 0; i <= 20; i++) { // 1,000,000 -> 2진수 변환시 20자리이기 때문
            int next = now ^ (1 << i); // 한자리만 숫자 변경
            if (next > n || visited[next] != -1) continue;
            visited[next] = visited[now] + 1;
            ans = max(ans, visited[next]);
            q.push(next);
        }
    }
    cout << ans;
}
/*
단순계산 0 - 1,000,000 까지의 비밀번호 1,000,000개의 비밀번호와 비교
*/