#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<int> v;

bool solution(int target) {
    int left = 0;
    int right = v.size() - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (v[mid] == target) {
            return true;
        }
        else if (v[mid] < target) {
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

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        if (solution(tmp)) {
            cout << "1 ";
        }
        else {
            cout << "0 ";
        }
    }
}