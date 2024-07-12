#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

struct node {
	int num;
	int height;

	bool operator<(node right) const {
		if (height < right.height) { return false; }
		if (height > right.height) { return true; }

		return false;
	}
};

int n;
vector<int> v;
stack<node> s;
priority_queue<node> pq;

int main(int argc, char** argv) {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(0);
		s.push({i, tmp});
	}

	while (!s.empty()) {
		node now = s.top();
		s.pop();

		while (!pq.empty() && now.height >= pq.top().height) {
			v[pq.top().num] = now.num + 1;
			pq.pop();
		}

		pq.push(now);
	}

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
}