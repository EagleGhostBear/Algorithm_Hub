#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

struct compare {
    bool operator()(vector<vector<int>> a, vector<vector<int>> b) {
        int a_sz = a[1].size(), b_sz = b[1].size();

        if (a_sz > b_sz) return true;
        if (a_sz < b_sz) return false;

        if (a_sz == b_sz && a_sz > 1 && b_sz > 1) {
            for (int i = a_sz - 1; i > 0; i--) {
                if (a[1][i] == b[1][i]) continue;
                if (a[1][i] > b[1][i]) return true;
                if (a[1][i] < b[1][i]) return false;
            }
        }

        // size가 1인것들은 실질적으로 없는것이므로 확인안해도 된다.
        return false;
    }
};

int n, k;
// total[i][0] = 원래 문자배열, total[i][1] = Z로 바꿨을때 이득보는 차이
vector<vector<vector<int>>> total(36, vector<vector<int>>(2, vector<int>(53, 0)));
vector<int> ans(53, 0);

void is_add(int num, int gap_val, int cnt, int type) {
    int ret = total[num][type][cnt] + gap_val;
    if (ret > 35) {
        total[num][type][cnt] = ret % 36;
        is_add(num, ret / 36, cnt + 1, type);
    }
    else total[num][type][cnt] += gap_val;
}
void ans_add(int cnt, int num) {
    int ret = ans[cnt] + num;
    if (ret > 35) {
        ans[cnt] = ret % 36;
        ans_add(cnt + 1, ret / 36);
    }
    else ans[cnt] += num;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < 36; i++) {
        total[i][0][0] = i;
        total[i][1][0] = i;
    }
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int cnt = 0;
        for (int j = s.size() - 1; j > -1; j--) {
            int num = 0;
            if ('0' <= s[j] && s[j] <= '9') num = s[j] - '0';
            else num = s[j] - 'A' + 10;
            is_add(num, 1, cnt + 1, 0);
            is_add(num, 35 - num, cnt + 1, 1); // Z로 치환했을때 이득 값을 저장
            cnt++;
        }
    }
    cin >> k;

    for (int i = 0; i < 36; i++) {
        int sz = total[i][0].size() - 1;
        for (int j = sz; j > 0; j--) { // 각 total[i][0] 번은 제외
            if (!total[i][0][j]) {
                total[i][0].pop_back();
            }
            else break;
        }
        sz = total[i][1].size() - 1;
        for (int j = sz; j > 0; j--) { // 각 total[i][0] 번은 제외
            if (!total[i][1][j]) {
                total[i][1].pop_back();
            }
            else break;
        }
    }

    sort(total.begin(), total.end(), compare());

    for (int i = 0; i < 36; i++) {
        if (k > 0 && total[i][1][0] != 35) { // 이미 Z이거나 바꾼건 넘겨야한다.
            total[i][1][0] = 35;
            k--;
        }
    }

    for (int i = 0; i < 36; i++) {
        for (int j = 1; j < total[i][0].size(); j++) {
            if (total[i][0][j]) ans_add(j - 1, total[i][1][0] * total[i][0][j]);
        }
    }

    for (int i = 52; i > -1; i--) {
        if (!ans[i]) ans.pop_back();
        else break;
    }
    if (ans.empty()) {
        cout << "0";
        return 0;
    }
    for (int i = ans.size() - 1; i > -1; i--) {
        if (ans[i] > 9) cout << char(ans[i] - 10 + 'A');
        else cout << char(ans[i] + '0');
    }
}
/*
36진법수에서 K개의 숫자를 Z로 바꾸었을때 전체 숫자의 합이 최대가 되는 값을 찾아라
*/