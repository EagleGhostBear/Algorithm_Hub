#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct node {
    int start;
    int end;
    int cap;

    bool operator<(node right) const {
        if (end < right.end) { return false; }
        if (end > right.end) { return true; }

        if (start < right.start) { return false; }
        if (start > right.start) { return true; }

        return false;
    }
};

int n, c, m;
int total = 0;
vector<int> cap;
priority_queue<node> pq;

int main(int argc, char** argv) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> c;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        pq.push({ a-1, b-1, c });
    }
    for (int i = 0; i < n; i++) {
        cap.push_back(c);
    }

    while (!pq.empty()) {
        node now = pq.top();
        pq.pop();

        int minv = 1e9;
        for (int i = now.start; i < now.end; i++) {
            minv = min(minv, cap[i]);
        }

        if (now.cap > minv) { // 남은 공간 보다 물량이 더 많을 때
            for (int i = now.start; i < now.end; i++) {
                cap[i] -= minv;
            }
            total += minv;
        }
        else { // 물량을 남은 공간에 다 넣을 수 있을 때
            for (int i = now.start; i < now.end; i++) {
                cap[i] -= now.cap;
            }
            total += now.cap;
        }
    }

    cout << total;
}