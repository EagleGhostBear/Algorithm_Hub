#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

struct node {
	int height;
	int cnt;

	bool operator<(node right) const {
		if (height < right.height) { return false; }
		if (height > right.height) { return true; }

		return false;
	}
};

int n;
long long total = 0;
stack<int> s;
priority_queue<int, vector<int>, greater<int>> pq;

int main(int argc, char** argv) {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;

		while (!pq.empty() && tmp >= pq.top()) {
			pq.pop();
		}

		total += pq.size();

		pq.push(tmp);
	}

	cout << total;
}