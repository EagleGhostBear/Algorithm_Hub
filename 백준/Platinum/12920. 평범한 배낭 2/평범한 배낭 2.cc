#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

struct node {
    int weight;
    int happy;
    int cnt;
};

int n, m;
vector<node> item;
vector<int> bag; // bag[가방 무게] = 행복도
vector<vector<int>> item_cnt; // item_cnt[가방 무게][아이템 index] = 사용 개수

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    bag.resize(m+1);
    item_cnt.resize(m + 1, vector<int>(n, 0));
    bag[0] = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int v, c, k;
        cin >> v >> c >> k;
        item.push_back({ v, c, k });
    }

    for (int w = 1; w <= m; w++) {
        int item_idx = -1;
        for (int j = 0; j < item.size(); j++) {
            node now = item[j];
            if (w >= now.weight && bag[w] < bag[w - now.weight] + now.happy && now.cnt - item_cnt[w - now.weight][j]) {
                bag[w] = bag[w - now.weight] + now.happy;
                item_idx = j;
                item_cnt[w] = item_cnt[w - now.weight];
                ans = max(ans, bag[w]);
            }
        }
        if (item_idx != -1) {
            item_cnt[w][item_idx] += 1;
        }
    }

    cout << ans;
}