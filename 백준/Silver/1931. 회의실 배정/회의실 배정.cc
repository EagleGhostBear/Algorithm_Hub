#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct node {
	int start;
	int end;

	bool operator<(node right) const {
		if (end < right.end) { return false; }
		else if (end > right.end) { return true; }

		if (start < right.start) { return false; }
		else if (start > right.start) { return true; }

		return false;
	}
};

int n;
int cnt = 0;
priority_queue<node> pq;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		pq.push({ a, b });
	}

	int endt = 0;

	while (!pq.empty()) {
		node now = pq.top();
		pq.pop();

		if (endt <= now.start) {
			cnt += 1;
			endt = now.end;
		}
	}

	cout << cnt;
}