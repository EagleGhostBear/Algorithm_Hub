#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

struct node {
	int idx;
	int val;

	bool operator<(node right) const {
		if (val < right.val) { return false; }
		if (val > right.val) { return true; }

		if (idx < right.idx) { return false; }
		if (idx > right.idx) { return true; }

		return false;
	}
};

int n;
vector<int> v;
priority_queue<node> pq;

int main(int argc, char** argv) {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		int now;
		cin >> now;

		while (!pq.empty() && now > pq.top().val) {
			v[pq.top().idx] = now;
			pq.pop();
		}

		pq.push({ i, now });
	}

	while (!pq.empty()) {
		node now = pq.top();
		pq.pop();

		v[now.idx] = -1;
	}

	for (int i = 0; i < n; i++) {
		cout << v[i] << " ";
	}
}