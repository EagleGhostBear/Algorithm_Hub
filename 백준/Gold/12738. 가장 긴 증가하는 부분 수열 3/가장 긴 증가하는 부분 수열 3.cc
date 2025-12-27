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

    int n;
    cin >> n;
    vector<int> lis;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (lis.empty() || lis.back() < num) lis.push_back(num);
        else {
            int left = 0, right = lis.size() - 1;
            int mid = 0;
            while (left <= right) {
                mid = (left + right) / 2;
                if (left == right) break;
                else if (num <= lis[mid]) right = mid;
                else left = mid + 1;
            }
            lis[mid] = num;
        }
    }
    cout << lis.size();
}