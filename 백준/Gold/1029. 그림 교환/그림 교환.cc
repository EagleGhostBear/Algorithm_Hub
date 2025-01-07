#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

int n, ans = 0;
vector<vector<int>> v;
vector<vector<int>> dp; // dat[idx][거쳐간 예술가 비트마스크] = 최소가격, 해당 idx 예술가가 구입했던 최소가격

void solution(int idx, int price, int cnt, int visited) {
    if (dp[idx][visited] <= price) {
        return;
    }
    else {
        dp[idx][visited] = price;
        ans = max(ans, cnt);
    }

    for (int i = 0; i < v[idx].size(); i++) {
        if (visited & (1 << i) || v[idx][i] < price) { // 이미 방문 했거나, 현재 가격보다 저렴한 경우 방문X
            continue;
        }
        solution(i, v[idx][i], cnt + 1, visited | (1 << i));
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    v.resize(n, vector<int>(n));
    dp.resize(n, vector<int>((1 << n), 200)); // 실제로 만들어지는 idx는 (1 << n)-1 까지 만들어지므로 (1 << n) - 1 할 필요가 없다

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            v[i][j] = int(s[j] - '0');
        }
    }

    solution(0, 0, 1, 1);

    cout << ans;
}
/*
vector<vector<int>> dp; // dat[idx][거쳐간 예술가의 수] = 최소가격
위와 같이 설정할 경우 같은 예술가의 수라도 경로가 다르므로 최적이라고 볼 수 없음
*/