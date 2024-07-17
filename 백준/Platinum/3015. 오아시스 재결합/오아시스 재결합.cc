#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

struct node {
	int val;
	int cnt;
};

int n;
long long total = 0;
vector<node> v;

int main(int argc, char** argv) {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;

		while (!v.empty() && tmp > v.back().val) {
			total += v.back().cnt;
			v.pop_back();
		}

		bool chk = false;
		for (int i = v.size() - 1; i > -1; i--) {
			if (v[i].val == tmp) {
				chk = true;
				total += v[i].cnt;
				v[i].cnt += 1;
			}
			else if (v[i].val > tmp) {
				total += 1;
				break;
			}
			else {
				break;
			}
		}

		if (!chk) {
			v.push_back({tmp, 1});
		}
	}

	cout << total;
}