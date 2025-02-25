    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include <unordered_map>
    #include <queue>
    #include <string>
    #include <cmath>

    using namespace std;

    typedef long long ll;

    int n;

    int main() {
        ios_base::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);

        while (cin >> n) {
            if (!n) break;

            vector<int> v;
            v.resize(n + 1, 0);
            for (int i = 1; i <= n; i++) {
                v[i] = v[i - 1] + i;
            }

            cout << v[n] << "\n";
        }
    }