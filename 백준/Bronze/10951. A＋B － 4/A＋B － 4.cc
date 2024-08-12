#include <iostream>

using namespace std;

int a, b;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

	while (cin >> a >> b) {
		cout << a + b << '\n';
	}

	return 0;
}