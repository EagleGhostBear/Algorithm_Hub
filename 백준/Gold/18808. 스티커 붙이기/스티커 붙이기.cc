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

int n, m, k, ans = 0;
vector<vector<vector<vector<int>>>> sticker;
vector<int> cnt;
vector<pair<int, int>> avail;

bool is_chk(int row, int col, vector<vector<int>>& s, vector<vector<int>>& board) {
    if (row + s.size() - 1 >= n || col + s[0].size() - 1 >= m) return true;
    for (int i = 0; i < s.size(); i++) for (int j = 0; j < s[i].size(); j++) {
        if (board[row + i][col + j] && s[i][j]) return true;
    }
    return false;
}

vector<vector<int>> paste_sticker(int row, int col, vector<vector<int>>& s, vector<vector<int>>& board) {
    vector<vector<int>> tmp = board;
    for (int i = 0; i < s.size(); i++) for (int j = 0; j < s[i].size(); j++) {
        tmp[row + i][col + j] += s[i][j];
    }
    return tmp;
}

void solve(int level, int idx, int now, vector<vector<int>> board) {
    if (idx == k - 1) {
        ans = max(ans, now);
        return;
    }

    for (int i = idx + 1; i < sticker.size(); i++) for (int j = 0; j < 4; j++) {
        if (ans) return;
        for (int row = 0; row < n; row++) for (int col = 0; col < m; col++) {
            if (is_chk(row, col, sticker[i][j], board)) continue;
            solve(level - 1, i, now + cnt[i], paste_sticker(row, col, sticker[i][j], board));
        }
        if (ans == 0 && (i == sticker.size() - 1 && j == 3)) { // 마지막까지 최초로 다 확인한 경우
            ans = max(ans, now);
            return;
        }
    }
    return;
}

vector<vector<int>> rotat_sticker(vector<vector<int>> ori) {
    int row = ori.size(), col = ori[0].size();
    vector<vector<int>> rotat(col, vector<int>(row, 0));
    for (int i = 0; i < row; i++) for (int j = 0; j < col; j++) {
        rotat[j][row - 1 - i] = ori[i][j];
    }
    return rotat;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;
    cnt.assign(k, 0);
    avail.assign(k, { -1, -1 });
    for (int t = 0; t < k; t++) {
        int row, col;
        cin >> row >> col;
        vector<vector<vector<int>>> oriSet;
        vector<vector<int>> ori(row, vector<int>(col, 0));
        for (int i = 0; i < row; i++) for (int j = 0; j < col; j++) {
            cin >> ori[i][j];
            if (ori[i][j]) cnt[t]++;
        }
        oriSet.push_back(ori);
        for (int i = 0; i < 3; i++) {
            ori = rotat_sticker(ori);
            oriSet.push_back(ori);
        }
        sticker.push_back(oriSet);
    }
    vector<vector<int>> board(n, vector<int>(m, 0));
    solve(k, -1, 0, board);
    cout << ans;
}
/*
1 2
3 4
5 6

5 3 1
6 4 2

(0,0) -> (0,2)
(0,1) -> (1,2)
(1,0) -> (0,1)
(1,1) -> (1,1)
(2,0) -> (0,0)
(2,1) -> (1,0)

(0,0) -> (0,3)
(x, y) -> (y, n-x)

어떤 스티커를 사용하고 사용하지 않을지도 골라야함
*/