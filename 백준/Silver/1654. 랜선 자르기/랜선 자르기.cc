#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

long long n, k;
vector<long long> v;

long long solution(long long target) {
    long long cnt = 0;
    for (long long i = 0; i < k; i++) {
        long long now = v[i] / target;
        if (!now) {
            break;
        }
        else {
            cnt += now;
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> k >> n;
    v.resize(k);
    for (long long i = 0; i < k; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end(), greater<int>());

    long long left = 1;
    long long right = v.front();
    long long ans;

    while (left <= right) {
        long long mid = (left + right) / 2;
        long long val = solution(mid);
        if (n <= val) {
            ans = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    cout << ans;
}