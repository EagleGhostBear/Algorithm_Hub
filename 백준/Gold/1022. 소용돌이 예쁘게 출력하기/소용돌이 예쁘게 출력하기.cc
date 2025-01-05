#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

int r1, c1, r2, c2, maxv = 0, len = 0;
vector<vector<int>> ans;

int solution(int row, int col) {
    int cnt = max(abs(row), abs(col));
    int val = 2 * cnt + 1;
    vector<int> tmp(4);
    tmp[0] = pow(val, 2);
    tmp[1] = tmp[0] - val + 1;
    tmp[2] = tmp[1] - val + 1;
    tmp[3] = tmp[2] - val + 1;

    if (row == cnt && col <= cnt) {
        return tmp[0] - (cnt - col);
    }
    else if (col == -cnt && row <= cnt) {
        return tmp[1] - (cnt - row);
    }
    else if (row == -cnt && col >= -cnt) {
        return tmp[2] -cnt - col;
    }
    else if (col == cnt && row >= -cnt) {
        return tmp[3] -cnt - row;
    }
}

void add_space(int sz) {
    for (int i = 0; i < len - sz; i++) {
        cout << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> r1 >> c1 >> r2 >> c2;

    ans.resize(r2 - r1 + 1, vector<int>(c2 - c1 + 1, 0));

    for (int i = 0; i <= r2 - r1; i++) {
        for (int j = 0; j <= c2 - c1; j++) {
            ans[i][j] = solution(i + r1, j + c1);
            maxv = max(maxv, ans[i][j]);
        }
    }

    len = to_string(maxv).size();

    for (int i = 0; i <= r2 - r1; i++) {
        for (int j = 0; j <= c2 - c1; j++) {
            add_space(to_string(ans[i][j]).size());
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}

/*
가로 5
세로 50
+ 1자리 수 길이 맞추기
*/