#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

int n;
vector<int> v;

int solution(int target) { // 이분탐색으로 target과 같거나 가장 근접하게 큰 수를 찾는다.
    int left = 0;
    int right = v.size() - 1;
    int mid;

    while (left <= right) {
        mid = (left + right) / 2;
        if (v[mid] == target) {
            break;
        }
        else if (target < v[mid]) { // 큰것 중에 가장 근접한 수
            if (left == right) {
                break;
            }
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }
    return mid;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;

        if (!v.empty() && tmp <= v.back()) {
            int idx = solution(tmp);
            //cout << "change: " << v[idx] << " -> " << tmp << "\n";
            v[idx] = tmp;
        }
        else {
            v.push_back(tmp);
        }
    }

    cout << v.size();
}