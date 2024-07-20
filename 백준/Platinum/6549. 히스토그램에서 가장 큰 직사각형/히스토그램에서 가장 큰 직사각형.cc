#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

struct node {
	long long val;
	long long cnt;

	bool operator<(node right) const {
		if (val < right.val) { return true; }
		if (val > right.val) { return false; }

		if (cnt < right.cnt) { return true; }
		if (cnt > right.cnt) { return false; }

		return false;
	}
};

int n;
priority_queue<node> pq;

int main(int argc, char** argv) {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	while (1) {
		cin >> n;
		if (n == 0) { break; }
		long long maxv = 0;
		for (int i = 0; i < n; i++) {
			long long tmp;
			cin >> tmp;

			long long tmp_cnt = 0;
			while (!pq.empty() && tmp <= pq.top().val) {
				node now = pq.top();
				pq.pop();
				maxv = max(maxv, now.val * (now.cnt + tmp_cnt));
				tmp_cnt += now.cnt;
			}
			pq.push({ tmp, 1 + tmp_cnt });
		}

		long long tmp_cnt = 0;
		while (!pq.empty()) {
			node now = pq.top();
			pq.pop();
			maxv = max(maxv, now.val * (now.cnt + tmp_cnt));
			tmp_cnt += now.cnt;
		}

		cout << maxv << "\n";
	}
}