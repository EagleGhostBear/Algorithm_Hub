#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int n;
vector<vector<int>> v;
vector<int> dp;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    v.resize(n, vector<int>());
    for (int i = 0; i < n; i++) {
        v[i].resize(i + 1);
        for (int j = 0; j < i+1; j++) {
            cin >> v[i][j];
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            if (j == 0) {
                v[i][j] += v[i - 1][j];
            }
            else if (j == i) {
                v[i][j] += v[i - 1][j - 1];
            }
            else {
                v[i][j] += max(v[i - 1][j - 1], v[i - 1][j]);
            }
        }
    }

    int ans = 0;
    for (auto data : v[n - 1]) {
        ans = max(ans, data);
    }

    cout << ans;
}
// 아래층으로 내려갈때 왼쪽, 오른쪽 대각선중 하나로 이동가능