#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<string>

using namespace std;

int n;
int total = 0;
stack<int> v;

int main(int argc, char** argv)
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v.push(tmp);
    }

    int prev = v.top();
    v.pop();

    while (!v.empty()) {
        int now = v.top();
        v.pop();

        if (now >= prev) {
            if (prev == 1) { continue; }
            total += (now - prev + 1);
            prev -= 1;
        }
        else {
            prev = now;
        }
    }

    cout << total;
}