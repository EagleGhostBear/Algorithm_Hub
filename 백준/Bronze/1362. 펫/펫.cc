    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include <unordered_map>
    #include <queue>
    #include <string>
    #include <cmath>

    using namespace std;

    typedef long long ll;

    int o, w, n, t = 1;
    char c;

    int main() {
        ios_base::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);

        while (cin >> o >> w) {
            if (o == 0 && w == 0) break;

            while (cin >> c >> n) {
                if (c == '#') break;
                else if (w <= 0) continue;
                else if (c == 'E') w -= n;
                else if (c == 'F') w += n;
            }

            cout << t++;
            if (o / 2 < w && w < o * 2) cout << " :-)\n";
            else if (w <= 0) cout << " RIP\n";
            else cout << " :-(\n";
        }
    }