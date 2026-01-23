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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    int ans = 0, cntK = 0;
    int left = 0, right = -1;
    while (left < n && ++right < n) {
        if (v[right] % 2) cntK++;
        while (cntK > k) if (v[left++] % 2) cntK--;
        ans = max(ans, right - left + 1 - cntK);
    }
    cout << ans;
}
/*
짝수를 최대 k개 가지고 있는 가장 긴 수열의 길이
*/