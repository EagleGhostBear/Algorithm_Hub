#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<string>

using namespace std;

int t, n;
stack<long long> v;

int main(int argc, char** argv)
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> t;
    for (int k = 0; k < t; k++) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            long long tmp;
            cin >> tmp;
            v.push(tmp);
        }

        long long total = 0;

        while (!v.empty()) {
            long long now = v.top();
            v.pop();

            if (!v.empty() && v.top() > now) {
                continue;
            }
            while (!v.empty() && v.top() <= now) {
                long long prev = v.top();
                v.pop();

                total += (now - prev);
            }
        }

        cout << total << "\n";
    }
}