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
int maxv = 0;
priority_queue<node> pq;
priority_queue<int, vector<int>, greater<int>> study;

int main(int argc, char** argv) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        pq.push({ a, b });
    }

    int now_time;
    while (!pq.empty()) {
        node now = pq.top();
        now_time = now.start;
        study.push(now.end);
        pq.pop();

        while (!study.empty() && study.top() <= now_time) {
            study.pop();
        }

        int sz = study.size();
        maxv = max(maxv, sz);
    }

    cout << maxv;
}
