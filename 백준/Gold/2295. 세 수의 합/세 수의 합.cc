#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int n;
vector<int> v;
vector<int> sum;

bool solution(int target) {
    int left = 0;
    int right = sum.size() - 1;

    while (left <= right) { // 오름차순 정렬이므로 반대로 생각해야함
        int mid = (left + right) / 2;
        if (sum[mid] == target) {
            return true;
        }
        else if (sum[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    for (int i = 0; i < n; i++) { // 1,000,000
        for (int j = i; j < n; j++) {
            sum.push_back(v[i] + v[j]);
        }
    }

    sort(v.begin(), v.end());
    sort(sum.begin(), sum.end());

    for (int i = n - 1; i > -1; i--) {
        for (int j = i; j > -1; j--) {
            if (solution(v[i] - v[j])) {
                cout << v[i];
                return 0;
            }
        }
    }
}