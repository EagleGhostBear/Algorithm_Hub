#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
priority_queue<long long, vector<long long>, greater<long long>> pq;

int main(int argc, char** argv) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        long long tmp;
        cin >> tmp;
        pq.push(tmp);
    }

    for (int i = 0; i < m; i++) {
        long long a = pq.top();
        pq.pop();
        long long b = pq.top();
        pq.pop();

        pq.push(a + b);
        pq.push(a + b);
    }

    long long total = 0;
    while (!pq.empty()) {
        total += pq.top();
        pq.pop();
    }

    cout << total;
}
