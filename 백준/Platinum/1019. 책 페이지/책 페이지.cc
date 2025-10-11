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

int n;
vector<int> ans;

void add_cnt(int val, int cnt) {
    while (val) ans[val % 10] += cnt, val /= 10;
    return;
}

void solution(int num) {
    int cnt = 1; // 자리수가 올라갈때마다 끝자리를 9로 처리했던 항목들을 *10, *100, ... 으로 처리하기 위해
    while (num / 10) { // 2자리 이상일때
        int prev_sz = to_string(num).size();
        while (num % 10 != 9) add_cnt(num--, cnt); // 끝자리를 9로 맞춤, 그러면 마지막 자리수는 *10으로 처리하면 되기 때문에
        int sz = to_string(num).size();
        if (prev_sz != sz) return; // 1000 같이 빼면 자리수가 바뀌면 종료

        num /= 10;
        sz = to_string(num).size();
        int val = num - pow(10, sz - 1) + 1;
        for (int i = 0; i < 10; i++) ans[i] += (val * cnt);
        cnt *= 10;
    }
    for (int i = 1; i <= num; i++) ans[i] += cnt;
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    ans.assign(10, 0);
    string tmp = "9";
    while (tmp.size() < to_string(n).size()) { // 해당 자리수 이전까지 처리, 1-9, 10-99, 100-999, ...
        solution(stoi(tmp));
        tmp += '9';
    }
    solution(n);
    for (auto num : ans) cout << num << " ";
}