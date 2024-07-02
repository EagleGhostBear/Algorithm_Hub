#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<string>

using namespace std;

int n;
int total = 0;
priority_queue<int> pq1; // 양
priority_queue<int, vector<int>, greater<int>> pq2; // 음

int main(int argc, char** argv)
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        if (tmp > 0) {
            pq1.push(tmp);
        }
        else {
            pq2.push(tmp);
        }
    }

    while (pq1.size() > 1) {
        int fir = pq1.top();
        pq1.pop();

        int sec = pq1.top();
        pq1.pop();

        if (fir * sec >= fir + sec) {
            total += (fir * sec);
        }
        else {
            total += (fir + sec);
        }
    }
    if (!pq1.empty()) {
        total += pq1.top();
    }

    while (pq2.size() > 1) {
        int fir = pq2.top();
        pq2.pop();

        int sec = pq2.top();
        pq2.pop();

        if (fir * sec >= fir + sec) {
            total += (fir * sec);
        }
    }
    if (!pq2.empty()) {
        total += pq2.top();
    }

    cout << total;
}