#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

int n, m;
vector<int> row, col;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    row.resize(n, 1);
    col.resize(m, 1);

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            if (s[j] == 'X') {
                row[i] = 0;
                col[j] = 0;
            }
        }
    }

    int total = 0, row_num = 0, col_num = 0;
    for (auto num : row) {
        if (num) {
            row_num++;
        }
    }
    for (auto num : col) {
        if (num) {
            col_num++;
        }
    }

    while (row_num && col_num) {
        row_num--;
        col_num--;
        total++;
    }
    total += (row_num + col_num);
    cout << total;
}
/*
s = 시간
*/