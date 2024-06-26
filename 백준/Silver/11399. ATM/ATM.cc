#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int n;
int cnt = 0;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		pq.push(tmp);
	}

	int total = 0;
	while (!pq.empty()) {
		int now = pq.top();
		pq.pop();
		total += (now + cnt);
		cnt += now;
	}

	cout << total;
}