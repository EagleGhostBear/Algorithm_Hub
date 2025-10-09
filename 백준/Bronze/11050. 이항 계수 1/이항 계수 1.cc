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
#include <iomanip>

using namespace std;

typedef long long ll;

int n, k;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    int num = 1;
    for (int i = n - k + 1; i <= n; i++) num *= i;
    for (int i = 2; i <= k; i++) num /= i;
    cout << num;
}