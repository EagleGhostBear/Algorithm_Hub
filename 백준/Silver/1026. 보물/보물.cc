#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int n;
int cnt = 0;
priority_queue<int, vector<int>, greater<int>> pq1;
priority_queue<int, vector<int>, less<int>> pq2;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		pq1.push(tmp);
	}
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		pq2.push(tmp);
	}
	for (int i = 0; i < n; i++) {
		cnt += pq1.top() * pq2.top();
		pq1.pop();
		pq2.pop();
	}
	cout << cnt;
}