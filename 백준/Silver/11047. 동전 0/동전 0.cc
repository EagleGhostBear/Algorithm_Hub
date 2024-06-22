#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int n, k;
priority_queue<int> pq;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		pq.push(tmp);
	}

	int cnt = 0;
	while (k != 0) {
		int now = pq.top();
		pq.pop();

		cnt += k / now;
		k %= now;
	}

	cout << cnt;
}