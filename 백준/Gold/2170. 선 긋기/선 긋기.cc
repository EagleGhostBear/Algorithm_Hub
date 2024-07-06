#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct node {
    int start;
    int end;

    bool operator<(node right) const {
        if (start < right.start) { return false; }
        if (start > right.start) { return true; }

        if (end < right.end) { return false; }
        if (end > right.end) { return true; }

        return false;
    }
};

int n;
int total = 0;
priority_queue<node> pq;

int main(int argc, char** argv) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        pq.push({ a, b });
    }

    while (!pq.empty()) {
        node now = pq.top();
        pq.pop();
        int now_start = now.start;
        int now_end = now.end;

        while (!pq.empty() && pq.top().start <= now_end) {
            now_end = max(now_end, pq.top().end);
            pq.pop();
        }

        total += (now_end - now_start);
    }

    cout << total;
}