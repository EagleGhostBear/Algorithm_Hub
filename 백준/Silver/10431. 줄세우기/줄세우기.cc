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

int t;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while (t--) {
        int n, cnt = 0;
        cin >> n;
        vector<int> v(20);
        for (int i = 0; i < 20; i++) cin >> v[i];
        for (int i = 1; i < 20; i++) { // 정렬할 숫자
            for (int j = 0; j < i; j++) {
                if (v[j] > v[i]) { // 앞에서 부터 확인해서 정렬한 위치 찾기
                    int tmp = v[i];
                    for (int k = i - 1; k >= j; k--) v[k + 1] = v[k], cnt++;
                    v[j] = tmp;
                    break;
                }
            }
        }
        cout << n << " " << cnt << "\n";
    }
}
/*
*/