#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int n;
int maxv = 0;
priority_queue<int> pq;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		pq.push(tmp);
	}

	int cnt = pq.size();
	for (int i = 1; i <= cnt; i++) {
		int now = pq.top();
		pq.pop();

		if (maxv < now * i) {
			maxv = now * i;
		}
	}

	cout << maxv;
}