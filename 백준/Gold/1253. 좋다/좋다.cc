#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <string>
#include <cmath>
#include <bitset>
#include <array>

using namespace std;

typedef long long ll;

int n, ans = 0;
unordered_map<int, int> um;
vector<int> v;
vector<int> chk;

void solution(int num1, int num2) {
    int target = num1 + num2;
    int left = 0;
    int right = v.size() - 1;

    if (target == num1 && um[num1] == 1) { // 0 + 1 = 1 
        return;
    }
    if (target == num2 && um[num2] == 1) { // 0 + 0 = 0 (단, 0이 2개밖에 없는 경우)
        return;
    }
    if (!num1 && !num2 && um[num1] <= 2) {
        return;
    }

    while (left <= right) {
        int mid = (left + right) / 2;
        if (v[mid] == target) {
            chk[mid] = 1;
            return;
        }
        else if (v[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        um[v[i]]++;
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    chk.resize(v.size(), 0);

    for (int i = 0; i < v.size(); i++) {
        for (int j = i + 1; j < v.size(); j++) {
            //cout << v[i] << " + " << v[j] << "\n";
            solution(v[i], v[j]);
        }
    }
    for (auto data : um) { // 중복 수 처리
        if (data.second > 1) {
            solution(data.first, data.first);
        }
    }

    for (int i = 0; i < chk.size(); i++) {
        if (chk[i]) {
            ans += um[v[i]];
        }
    }

    cout << ans;
}
/*
unique 함수로 중복된 수를 압축하면 중복된 수끼리 생기는 가능성을 고려해야함
*/