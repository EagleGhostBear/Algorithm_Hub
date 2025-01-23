#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

int s, n, k, r1, r2, c1, c2, per;
vector<vector<int>> v;

int solution(int row, int col, int level) {
    if (level == 1) { // 기본 사각형이면 바로 출력
        return v[row][col];
    }

    int num = pow(n, level) / n;
    if (num * per <= row && row < num * (n-per) && num * per <= col && col < num * (n - per)) { // 가운데 사각형 위치면 바로 1 return
        return 1;
    }
    else { // 가운데 사각형이 아니라면 사이즈 압축
        return solution(row % num, col % num, level - 1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> s >> n >> k >> r1 >> r2 >> c1 >> c2;

    v.resize(n, vector<int>(n, 0)); // 시간 1일때의 기본 사각형
    per = (n - k) / 2;
    for (int i = per; i < per + k; i++) {
        for (int j = per; j < per + k; j++) {
            v[i][j] = 1;
        }
    }

    if (!s) {
        cout << "0";
    }
    else {
        for (int i = r1; i <= r2; i++) {
            for (int j = c1; j <= c2; j++) {
                cout << solution(i, j, s);
            }
            cout << "\n";
        }
    }
}
/*
s, n, k
길이 = n^s
27 = 9 ~ 17
9(1/3) ~ 18(2/3)
*/