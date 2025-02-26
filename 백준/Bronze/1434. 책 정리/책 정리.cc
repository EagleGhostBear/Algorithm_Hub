    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include <unordered_map>
    #include <queue>
    #include <string>
    #include <cmath>

    using namespace std;

    typedef long long ll;

    int n, m;
    vector<int> box, book;

    int main() {
        ios_base::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);

        cin >> n >> m;
        box.resize(n); book.resize(m);
        for (int i = 0; i < n; i++) cin >> box[i];
        for (int i = 0; i < m; i++) cin >> book[i];

        int ans = 0, idx = 0;
        for (int i = 0; i < n; i++) {
            int now_box = box[i];
            for (; idx < m; idx++) {
                if (book[idx] <= now_box) {
                    now_box -= book[idx];
                }
                else break;
            }
            ans += now_box;
        }

        cout << ans;
    }