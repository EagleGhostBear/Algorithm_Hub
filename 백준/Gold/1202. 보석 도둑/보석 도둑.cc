#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<string>

using namespace std;

struct node {
    int weight;
    int val;

    bool operator<(node right) const {
        if (weight < right.weight) { return false; }
        if (weight > right.weight) { return true; }

        if (val < right.val) { return true; }
        if (val > right.val) { return false; }

        return false;
    }
};

int n, k;
long long total = 0;
priority_queue<node> pq;
priority_queue<int, vector<int>, greater<int>> bag;

int main(int argc, char** argv)
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        pq.push({ a, b });
    }
    for (int i = 0; i < k; i++) {
        int tmp;
        cin >> tmp;
        bag.push(tmp);
    }

    priority_queue<int> tmp;
    while (!bag.empty()) {
        int now_b = bag.top();
        bag.pop();
        while (!pq.empty() && pq.top().weight <= now_b) {
            tmp.push(pq.top().val);
            pq.pop();
        }
        if (!tmp.empty()) {
            total += tmp.top();
            tmp.pop();
        }
    }

    cout << total;
}